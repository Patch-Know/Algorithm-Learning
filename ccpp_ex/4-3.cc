#include<iostream>
#include<cstring>
const int Size=30;

int main(){
    using namespace std;
    char fname[Size];
    char lname[Size];
    cout << "What is your first name? ";
    cin.getline(fname,Size);
    cout << "What is your last name? ";
    cin.getline(lname,Size);
    strncat(lname,",   ",2);
    strncat(lname,fname,Size-1);
    cout << "Here's the information in a single string: "
    << lname <<endl;
    return 0;
}