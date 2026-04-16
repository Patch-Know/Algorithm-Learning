#include<iostream>
#include<string>
struct Info
{
    std::string fname;
    std::string lname;
    char grade;
    int age;
};

int main(){
    using namespace std;
    Info stu;
    cout << "What is your first name? ";
    getline(cin,stu.fname);//NOTE
    cout << "What is your last name? ";
    getline(cin,stu.lname);//NOTE
    cout << "What letter grade do you deserve? ";
    cin >> stu.grade;
    cout << "What is your age? ";
    cin >> stu.age;
    cout << "Name: " << stu.lname <<", "
    << stu.fname <<endl<<"Grade: "<< char(stu.grade+1)
    <<endl<<"Age: "<< stu.age<<endl;

    return 0;
}
