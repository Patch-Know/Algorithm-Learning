#include<iostream>

using namespace std;

int main(){
    int row;
    cout<<"Enter number of rows: ";
    (cin>>row).get();
    int i,j,k;
    for (i=0;i<row;i++)
    {
        j=i+1;
        for (k=j;k<row;k++) cout.put('.');
        for (k=0;k<j;k++) cout.put('*');
        cout<<endl;
    }
    return 0;
}