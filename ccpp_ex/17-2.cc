#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int BLOCK = 512;

int main()
{
    ofstream fout;
    cout << "Enter a filename: ";
    string filename;
    cin >>filename;
    while (cin.get()!='\n') continue;
    fout.open(filename.c_str());
    char ch;
    while (cin.get(ch) && ch !=EOF)
    {
        fout << ch;
    }
    fout.close();
    return 0;
}