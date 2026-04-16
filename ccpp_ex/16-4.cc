#include<iostream>
#include<algorithm>
using namespace std;

int reduce(long ar[],int n);

const int Num = 10;
int main()
{
    long ar0[Num]{1,1,4,5,1,4,2,3,3,3};
    int newsize =reduce(ar0,Num);
    for (int i = 0;i< newsize ; i++){
        cout << ar0[i] <<",";
    }
    cout <<  endl << "New size: " << newsize ;
    return 0;
}

int reduce(long ar[],int n)
{
    sort(ar,ar+n);
    auto pos = unique(ar,ar+n);
    return pos - ar;
}