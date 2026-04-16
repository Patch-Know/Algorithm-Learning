#include<iostream>

using namespace std;

int main(){
    const int in_per_ft = 12;
    cout << "Enter your height in inch:___\b\b\b";
    int in;
    cin >> in;
    cout << "Your height is " << in/in_per_ft <<"ft "<<in%in_per_ft<<"in."<<endl;
    return 0;
}