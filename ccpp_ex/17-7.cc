#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

void ShowStr(const std::string &);
void GetStrs(std::ifstream &,std::vector<std::string> & );
class Store
{
private:
    std::ofstream & fileout;
public:
    Store(std::ofstream & of) : fileout(of){}
    void operator()(const std::string &);
};

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin,temp) && temp[0]!='\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(),vostr.end(),ShowStr);

    ofstream fout("strings.dat",ios_base::out|ios_base::binary);
    for_each(vostr.begin(),vostr.end(),Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin,vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(),vistr.end(),ShowStr);
    return 0;
}

void ShowStr(const std::string & s)
{
    std::cout << s <<std::endl;
}


void Store::operator()(const std::string & s)
{
    size_t len = s.length();
    fileout.write((char *)&len,sizeof(size_t));
    fileout.write(s.data(),len);
}

void GetStrs(std::ifstream & fin,std::vector<std::string> & vs)
{
    char lenarr[sizeof(size_t)];
    size_t * pd;
    char ch;
    while(fin.read(lenarr,sizeof(size_t))){
        pd = (size_t *) lenarr;
        std::string temp;
        for (size_t i=0;i< *pd;i++){
            fin.get(ch);
            temp+=ch;
        }
        vs.push_back(temp);
    }
}
