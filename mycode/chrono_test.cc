#include<iostream>
#include<chrono>
#include<string>
#include<random>
#include<thread>
using namespace std;
using namespace std::chrono;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    string s;
    uniform_real_distribution<> dice(2,5);
    double secs=dice(gen);
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