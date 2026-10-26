#include<iostream>
#include<chrono>
#include<string>
#include<random>
#include<thread>
#include<format>
using namespace std;
using namespace std::chrono;

int main()
{
    auto utc_now = std::chrono::system_clock::now();

    // 将 UTC 时间点与当前系统时区结合
    std::chrono::zoned_time lc_time{std::chrono::current_zone(), utc_now};
    std::cout << lc_time << std::endl;
    // std::string str_time = std::format("{:%F %T}", utc_now);  // %F=YYYY-MM-DD, %T=HH:MM:SS
    // std::cout << str_time << std::endl;

    random_device rd;
    mt19937 gen(rd());
    string s;
    uniform_real_distribution<> dice(2,5);
    double secs=dice(gen);
    cout << "Let's neovim" << endl;
    cout << "wait for a few seconds~" << endl << endl;
    this_thread::sleep_for(duration<double>(secs));
    cout << "NOW\nPRESS\nPRESS\nPRESS\nPRESS\nPRESS\nENTER!!!!!";
    auto start{high_resolution_clock::now()};
    getline(cin,s);
    auto finish{high_resolution_clock::now()};
    auto millis{duration_cast<milliseconds>(finish-start)};
    if(millis.count()<100){
        cout << "fail." << endl;
        return 0;
    }
    cout << millis << endl;
    if(millis.count()<200) cout << "~YOU WIN~" << endl;
}
