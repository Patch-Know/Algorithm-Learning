#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct box
{
    int label;
    int obj;
};


int main()
{
    int n,asks;
    cin >> n >> asks;
    vector<list<box>> larr(n);
    list<box>::iterator itr;
    int i,j,k;
    int choice;
    for (int a = 0; a < asks; a++)
    {
        cin>>choice>>i>>j;
        if(choice==1){
            cin>>k;
            cin.get();
            if(k>0)
            larr[i-1].push_back({j,k});
            else{
                itr=larr[i-1].begin();
                while(itr->label!=j) itr++;
                larr[i-1].erase(itr);
            }
        }else if(choice==2){
            itr=larr[i-1].begin();
            while(itr->label!=j) itr++;
            cout << itr->obj <<endl;
        }
    }
    
    return 0;
}