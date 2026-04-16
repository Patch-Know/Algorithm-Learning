#include<fstream>
#include<string>

using namespace std;

int main()
{
    ifstream fin1("dearMOM");
    ifstream fin2("donainfo");
    ofstream fout("somewords.txt");
    string s1,s2;
    while (fin1.peek()!=EOF && fin2.peek()!=EOF)
    {
        getline(fin1,s1);
        getline(fin2,s2);
        fout << s1+' '+s2<< endl;
    }
    while (fin1.peek()!=EOF)
    {
        getline(fin1,s1);
        fout << s1 << endl;
    }
    while (fin2.peek()!=EOF)
    {
        getline(fin2,s2);
        fout << s2 << endl;
    }
    fin1.close();
    fin2.close();
    fout.close();
    
    return 0;
}