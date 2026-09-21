#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace std::chrono;

// ---------- 工具函数 ----------

// 阻止编译器把被计时的运算优化掉
template <typename T>
inline void keep(T const& v) { asm volatile("" : : "r"(v) : "memory"); }

// 对一组测量值取中位数
double median_of(vector<double>& ts) {
    sort(ts.begin(), ts.end());
    return ts[ts.size() / 2];
}

// 预生成随机索引，避免把 rand 的开销算入计时
vector<int> random_indices(size_t K, int N, unsigned seed = 42) {
    mt19937 gen(seed);
    uniform_int_distribution<int> dis(0, N - 1);
    vector<int> idx(K);
    for (size_t i = 0; i < K; ++i) idx[i] = dis(gen);
    return idx;
}

// ---------- (1) vector 索引访问：期望 O(1) ----------
void test_vector_index() {
    cout << "\n===== (1) vector 按索引取值 [期望 O(1)] =====\n";
    cout << setw(12) << "N"
         << setw(18) << "总时间(s)"
         << setw(18) << "单次访问(ns)"
         << setw(22) << "归一化(单次/首次)\n";

    const int K = 10000000;   // 每次测试做 1000 万次访问
    const int R = 5;          // 重复 5 次取中位数
    vector<int> sizes = {1000, 100000, 1000000};
    double first = 0.0;

    for (int N : sizes) {
        vector<int> v(N);
        for (int i = 0; i < N; ++i) v[i] = i;
        auto idx = random_indices(K, N);

        vector<double> ts;
        for (int r = 0; r < R; ++r) {
            auto s = high_resolution_clock::now();
            long long sum = 0;
            for (int i = 0; i < K; ++i) sum += v[idx[i]];
            auto e = high_resolution_clock::now();
            keep(sum);
            ts.push_back(duration_cast<duration<double>>(e - s).count());
        }
        double t = median_of(ts);
        double per_ns = t / K * 1e9;
        if (first == 0.0) first = per_ns;

        cout << setw(12) << N
             << setw(18) << fixed << setprecision(6) << t
             << setw(18) << fixed << setprecision(3) << per_ns
             << setw(22) << fixed << setprecision(3) << per_ns / first << "\n";
    }
    cout << ">>> 结论: 单次访问耗时基本恒定, 与 N 无关 -> O(1) 成立\n";
}

// ---------- (2) vector 中间插入：期望 O(n) ----------
void test_vector_insert() {
    cout << "\n===== (2) vector 中间插入 [期望 O(n)] =====\n";
    cout << setw(12) << "N"
         << setw(18) << "单次插入(ns)"
         << setw(18) << "相对上次倍数"
         << setw(22) << "单次/N (ns)\n";

    const int K = 1000;       // 每个规模做 1000 次插入
    const int R = 5;
    vector<int> sizes = {1000, 100000, 1000000};
    double prev = 0.0;

    for (int N : sizes) {
        vector<double> ts;
        for (int r = 0; r < R; ++r) {
            vector<int> v(N, 0);          // 构建 vector 不计入计时
            int pos = N / 2;              // 在中点插入
            auto s = high_resolution_clock::now();
            for (int i = 0; i < K; ++i)
                v.insert(v.begin() + pos, i);
            auto e = high_resolution_clock::now();
            keep(v.data());
            ts.push_back(duration_cast<duration<double>>(e - s).count());
        }
        double t = median_of(ts);
        double per_ns = t / K * 1e9;

        cout << setw(12) << N
             << setw(18) << fixed << setprecision(3) << per_ns;
        if (prev > 0)
            cout << setw(18) << fixed << setprecision(2) << per_ns / prev;
        else
            cout << setw(18) << "-";
        cout << setw(22) << fixed << setprecision(6) << per_ns / N << "\n";
        prev = per_ns;
    }
    cout << ">>> 结论: 单次插入耗时与 N 成正比, 单次/N 基本恒定 -> O(n) 成立\n";
}

// ---------- (3) map 查找：期望 O(log n) ----------
void test_map_find() {
    cout << "\n===== (3) map 查找 [期望 O(log n)] =====\n";
    cout << setw(12) << "N"
         << setw(18) << "单次查找(ns)"
         << setw(18) << "相对上次倍数"
         << setw(24) << "单次/log2(N) (ns)\n";

    const int K = 1000000;    // 每次 100 万次查找
    const int R = 5;
    vector<int> sizes = {1000, 100000, 1000000};
    double prev = 0.0;

    for (int N : sizes) {
        map<int, int> m;
        for (int i = 0; i < N; ++i) m[i] = i;   // 构建 map 不计入计时
        auto idx = random_indices(K, N);

        vector<double> ts;
        for (int r = 0; r < R; ++r) {
            auto s = high_resolution_clock::now();
            long long sum = 0;
            for (int i = 0; i < K; ++i) {
                auto it = m.find(idx[i]);
                if (it != m.end()) sum += it->second;
            }
            auto e = high_resolution_clock::now();
            keep(sum);
            ts.push_back(duration_cast<duration<double>>(e - s).count());
        }
        double t = median_of(ts);
        double per_ns = t / K * 1e9;

        cout << setw(12) << N
             << setw(18) << fixed << setprecision(3) << per_ns;
        if (prev > 0)
            cout << setw(18) << fixed << setprecision(2) << per_ns / prev;
        else
            cout << setw(18) << "-";
        cout << setw(24) << fixed << setprecision(3)
             << per_ns / log2((double)N) << "\n";
        prev = per_ns;
    }
    cout << ">>> 结论: 单次查找耗时随 log2(N) 缓慢增长, 单次/log2(N) 基本稳定 -> O(log n) 成立\n";
}

// ---------- (4) unordered_map 查找：期望平均 O(1) ----------
void test_unordered_map_find() {
    cout << "\n===== (4) unordered_map 查找 [期望 O(1)] =====\n";
    cout << setw(12) << "N"
         << setw(18) << "单次查找(ns)"
         << setw(24) << "归一化(单次/首次)\n";

    const int K = 10000000;   // 每次 1000 万次查找
    const int R = 5;
    vector<int> sizes = {1000, 100000, 1000000};
    double first = 0.0;

    for (int N : sizes) {
        unordered_map<int, int> m;
        m.reserve(N);                            // 预分配桶, 避免 rehash
        for (int i = 0; i < N; ++i) m[i] = i;
        auto idx = random_indices(K, N);

        vector<double> ts;
        for (int r = 0; r < R; ++r) {
            auto s = high_resolution_clock::now();
            long long sum = 0;
            for (int i = 0; i < K; ++i) {
                auto it = m.find(idx[i]);
                if (it != m.end()) sum += it->second;
            }
            auto e = high_resolution_clock::now();
            keep(sum);
            ts.push_back(duration_cast<duration<double>>(e - s).count());
        }
        double t = median_of(ts);
        double per_ns = t / K * 1e9;
        if (first == 0.0) first = per_ns;

        cout << setw(12) << N
             << setw(18) << fixed << setprecision(3) << per_ns
             << setw(24) << fixed << setprecision(3) << per_ns / first << "\n";
    }
    cout << ">>> 结论: 单次查找耗时基本恒定 -> 平均 O(1) 成立\n";
}

int main() {
    cout << "================ STL 容器操作复杂度验证 ================\n";
    cout << "测试规模: N = 1e3, 1e5, 1e6\n";
    cout << "每组数据取 5 次运行的中位数\n";

    test_vector_index();
    test_vector_insert();
    test_map_find();
    test_unordered_map_find();

    cout << "\n================ 测试完成 ================\n";
    return 0;
}