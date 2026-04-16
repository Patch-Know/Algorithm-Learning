#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template<class T>
int reduce(T ar[],int n);

const int Num = 10;
const int Max = 12;
int main()
{
    //long ar0[Num]{1,1,4,5,1,4,2,3,3,3};
    string ar1[Max]={"BangDream","Poppin'Party","hehedaren","Afterglow","hehedaren","Roselia",
        "Roselia","hehedaren","Poppin'Party","PasPale","Poppin'Party","BangDream"};
    int newsize =reduce(ar1,Max);
    for (int i = 0;i< newsize ; i++){
        cout << ar1[i] <<",";
    }
    cout <<  endl << "New size: " << newsize ;
    return 0;
}

template<class T>
int reduce(T ar[],int n)
{
    sort(ar,ar+n);
    auto pos = unique(ar,ar+n);
    return pos - ar;
}