#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>

using namespace std;

int main()
{
    map<string,vector<pair<string,string>>> family;
    string temp,childname,birthday;
    cout << "Enter the family name: ";
    while (getline(cin,temp) && temp[0]!='\0')
    {
        cout << "Enter one child's name: ";
        while(getline(cin,childname) && childname[0]!='\0'){
            cout << "Enter the child's birthday: ";
            getline(cin,birthday);
            family[temp].push_back({childname,birthday});
            cout << "Enter one child's name: ";
        }
        cout << "Enter the family name: ";   
    }
    for(const auto & f : family){
        cout << "Family " << f.first << ":\n";
        cout << "member\tbirthday\n";
        for(const auto & m : f.second) cout << m.first << "   "<< m.second << endl;
    }
    return 0;
}