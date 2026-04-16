#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main()
{
    map<string,vector<string>> family;
    string temp,childname;
    cout << "Enter the family name: ";
    while (getline(cin,temp) && temp[0]!='\0')
    {
        cout << "Enter one child's name: ";
        while(getline(cin,childname) && childname[0]!='\0'){
            family[temp].push_back(childname);
            cout << "Enter one child's name: ";
        }
        cout << "Enter the family name: ";   
    }
    for(const auto & f : family){
        cout << "Family " << f.first << ":\n";
        for(const auto & m : f.second) cout << m << endl;
    }
    return 0;
}