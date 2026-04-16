#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    vector<string> Mat,Pat;
    vector<string> share;
    string temp;
    fin.open("mat.dat");
    if(!fin.is_open()){
        cerr << "Can't open file mat.dat\n";
        exit(EXIT_FAILURE);
    } 
    //cout << "Mat!Enter a name: ";
    while (getline(fin,temp) && temp!="" ){
        Mat.push_back(temp);
        //cout << "Mat!Enter a name: ";
    }
    fin.clear();
    fin.close();
    fin.open("pat.dat");
    if(!fin.is_open()){
        cerr << "Can't open file pat.dat\n";
        exit(EXIT_FAILURE);
    } 
    //cout << "Pat!Enter a name: ";
    while (getline(fin,temp) && temp!="" ){
        Pat.push_back(temp);
        //cout << "Pat!Enter a name: ";
    }
    fin.clear();
    fin.close();
    sort(Mat.begin(),Mat.end());
    sort(Pat.begin(),Pat.end());
    share.resize(Mat.size()+Pat.size());
    //  Now Right!!!
    merge(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),share.begin());
    size_t newsize = unique(share.begin(),share.end()) - share.begin();
    share.resize(newsize);
    fout.open("matnpat.dat");
    fout << "Here's the share namelist: \n";
    for(string & x:share) fout<<x<<endl;
    cout << "Done!\n";
    return 0;
}