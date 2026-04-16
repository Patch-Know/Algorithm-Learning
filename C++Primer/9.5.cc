#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

typedef vector<int> vint;

vint::iterator FindVInt(vint::iterator l,vint::iterator r,int x);

int main()
{
    vector<int> v0{2,3,3,5,1,4,9,9,6,1};
    cout.setf(ios_base::boolalpha);
    vint::iterator a;
    if((a=FindVInt(v0.begin(),v0.end(),7))!=v0.end()) cout << *a << endl;
    else cout << "Can't find!" << endl;
    return 0;
}



vint::iterator FindVInt(vint::iterator l,vint::iterator r,int x)
{
    vint::iterator i = l;
    while ((*i !=  x) && (i!=r))
    {
        i++;
    }
    return i;
}