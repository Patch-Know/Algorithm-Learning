#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<double>> a(n,vector<double>(m));
    vector<double> b(n);
    int cnt=0;
    for(auto & stu:a) for(auto & x:stu) cin >> x;
    for(auto & stu:a){
        double max= *max_element(stu.begin(),stu.end());
        double min= *min_element(stu.begin(),stu.end());
        b[cnt++]=(accumulate(stu.begin(),stu.end(),0.0)-max-min)/(m-2);
    }
    cout << fixed << setprecision(2) << *max_element(b.begin(),b.end());
    return 0;
}