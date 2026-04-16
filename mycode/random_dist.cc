#include<iostream>
#include<random>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    random_device rd;
    mt19937_64 gen(rd());
    binomial_distribution<int> dist(3000,0.001);
    //poisson_distribution<int> dist(3);

    int n = 70;
    vector<int> point(n);
    int temp;
    for(int i=0;i<500;i++){
        temp=static_cast<int>(lround(dist(gen)));
        if(temp>=0 && temp<n ) ++point[temp];
    }
    int cnt=0;
    cout << left;
    for(int x:point) cout << setw(3) << cnt++  <<": "<< string(x,'*') << '\n';
    return 0;
}