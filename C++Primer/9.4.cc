#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

typedef vector<int> vint;

bool FindVInt(vint::iterator l,vint::iterator r,int x);

int main()
{
    vector<int> v0{2,3,3,5,1,4,9,9,6,1};
    cout.setf(ios_base::boolalpha);
    cout << FindVInt(v0.begin(),v0.end(),6) << endl;
    return 0;
}



bool FindVInt(vint::iterator l,vint::iterator r,int x)
{
    bool has_element = false;
    for(vint::iterator i = l;i!=r;i++){if(*i==x){has_element=true;break;}}
    return has_element;
}