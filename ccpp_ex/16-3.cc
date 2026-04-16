#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("somewords.txt");
    string tmp;
    vector<string> sv;
    // int count = 0;
    // while (fin >> tmp)
    // {
    //     count++;
    // }
    // cout << count << " words in all.";
    while (fin >> tmp)
    {
        sv.push_back(tmp);
    }
    cout << sv.size() << " words in all.";
    
    return 0;
}