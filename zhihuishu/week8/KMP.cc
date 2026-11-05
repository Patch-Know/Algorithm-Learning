//KMP算法
//求解字符串所有出现位置

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string p,s;

int n,m;

vector<int> nxt;

vector<int> find_all() {
    vector<int> res;
    int i = 0;   // p 中待匹配位置 
    int j = 0;   // s 中当前扫描位置
    while (j < m) {
        if (s[j] == p[i]) {
            i++;
            j++;
            if (i == n) {              // 找到一个匹配
                res.push_back(j - n);
                i = nxt[n - 1] + 1;    // 继续找重叠匹配
            }
        } else if (i > 0) {
            i = nxt[i - 1] + 1;        // KMP 回退
        } else {
            j++;
        }
    }
    return res;
}

int main()
{
    cin >> n;
    cout << "模式串P: ";
    cin.ignore(); // 忽略掉换行符
    getline(cin, p);
    cin >> m;
    cout << "字符串S: ";
    cin.ignore(); // 忽略掉换行符
    getline(cin, s);

    if(n==0) return 0;

    //求解模式串的nxt数组
    nxt.resize(n);
    nxt[0]=-1;
    for(int i=1;i<n;i++){
        int j=nxt[i-1];
        while(j>=0 && p[i]!=p[j+1]){
            j=nxt[j];
        }
        if(p[i]==p[j+1]){
            nxt[i]=j+1;
        }else{
            nxt[i]=-1;
        }
    }

    vector<int> ans = find_all();
    for (int x : ans) cout << x << ' ';
}
