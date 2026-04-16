#include<iostream>
#include<vector>

using namespace std;

int MainElement(vector<int> v);

int main()
{
    vector<int> v0{1,2,2,1,2,1,5,2,5,2,2,5,2,6,6,6,6,2,2,2};
    cout << "Size: " << v0.size() << endl;
    cout << MainElement(v0) << endl;
    return 0;
}

//求大小为N的数组中出现数量超过N/2的元素
//如果没有这样的元素，返回-1

int MainElement(vector<int> v)
{
    if(v.size()==0) return -1;
    if(v.size()==1) return v[0];
    if(v.size()==2) return v[0]==v[1] ? v[0] : -1;
    vector<int> v2;
    int out;
    for (size_t i = 0; i < v.size()/2*2; i+=2)
    {
        if(v[i]==v[i+1]) v2.push_back(v[i]);
    }
    if((out=MainElement(v2))==-1 && (v.size()&1)){
        v2.push_back(v.back());
        return MainElement(v2);
    }
    return out; 
    
}
