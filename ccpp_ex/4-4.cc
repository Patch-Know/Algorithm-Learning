#include<iostream>
#include<string>

int main(){
    using namespace std;
    string fname,lname,name;
    cout << "What is your first name? ";
    getline(cin,fname);
    cout << "What is your last name? ";
    getline(cin,lname);
    name=lname+", "+fname;
    cout << "Here's the information in a single string: "
    << name <<endl;
    return 0;
}