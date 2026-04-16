#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

const size_t BIGNUM = 50000000;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> vi0(BIGNUM);
    for(int & x : vi0) x = rand();
    vector<int> vi(vi0.begin(),vi0.end());
    list<int> li(vi0.begin(),vi0.end());
    clock_t start,end;

    start = clock();
    sort(vi.begin(),vi.end());
    end = clock();
    cout << (double)(end-start)/CLOCKS_PER_SEC << "s"<<endl;

    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end-start)/CLOCKS_PER_SEC << "s"<<endl;

    //new random
    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> vi01(BIGNUM),vi2(BIGNUM);
    for(int & x : vi01) x = rand();
    sort(vi01.begin(),vi01.end());
    copy(vi01.begin(),vi01.end(),li.begin());
    start = clock();
    copy(li.begin(),li.end(),vi2.begin());
    sort(vi2.begin(),vi2.end());
    copy(vi2.begin(),vi2.end(),li.begin());
    end = clock();
    cout << (double)(end-start)/CLOCKS_PER_SEC << "s"<<endl;
    return 0;
}