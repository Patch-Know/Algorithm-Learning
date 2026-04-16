#include<iostream>
#include<string>
using namespace std;

struct car
{
    string make;
    int year;
};

int main(){
    int n;
    cout<<"How many cars do you wish to catalog? ";
    cin>>n;
    cin.get();
    car* arr_car=new car[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Car #"<<i+1<<":\n";
        cout<<"Please enter the make: ";
        getline(cin,arr_car[i].make);
        cout<<"Please enter the year made: ";
        cin>>arr_car[i].year;
        cin.get();
    }
    cout<<"Here is your collection:\n";
    for (int i=0;i<n;i++)
    {
        cout<<arr_car[i].year<<' '<<arr_car[i].make<<endl;
    }
    return 0;
}
