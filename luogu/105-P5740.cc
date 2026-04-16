#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct student
{
    string name;
    int yu;
    int shu;
    int yin;
};

int main()
{
    int n;
    cin>> n;
    vector<student> a(n);
    auto itmax = a.begin();
    int max=-1;
    
    for(auto it=a.begin();it!=a.end();it++){
        cin >> it->name >> it->yu >> it->shu >> it->yin;
        if(max < it->yu + it->shu + it->yin){
            max=it->yu + it->shu + it->yin;
            itmax=it;
        }
    }
    cout << itmax->name << ' ' << itmax->yu << ' ' << itmax->shu << ' ' << itmax->yin;
    return 0;
}