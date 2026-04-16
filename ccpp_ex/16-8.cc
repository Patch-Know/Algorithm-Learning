#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    vector<string> Mat,Pat;
    vector<string> share;
    string temp;
    cout << "Mat!Enter a name: ";
    while (getline(cin,temp) && temp!="" ){
        Mat.push_back(temp);
        cout << "Mat!Enter a name: ";
    }
    cout << "Pat!Enter a name: ";
    while (getline(cin,temp) && temp!="" ){
        Pat.push_back(temp);
        cout << "Pat!Enter a name: ";
    }
    sort(Mat.begin(),Mat.end());
    sort(Pat.begin(),Pat.end());
    share.resize(Mat.size()+Pat.size());
    //  Now Right!!!
    merge(Mat.begin(),Mat.end(),Pat.begin(),Pat.end(),share.begin());
    size_t newsize = unique(share.begin(),share.end()) - share.begin();
    share.resize(newsize);
    cout << "Here's the share namelist: \n";
    for(string & x:share) cout<<x<<endl;

    return 0;
}