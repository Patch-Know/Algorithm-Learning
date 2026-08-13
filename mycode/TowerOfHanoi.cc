//打印汉诺塔

#include<iostream>
#include<string>
using namespace std;

// if(i==1){
//     cout << "移动圆盘" << i << "从" << from << "到" << to << endl;
// }else{
//     f(i-1,from,other,to);
//     cout << "移动圆盘" << i << "从" << from << "到" << to << endl;
//     f(i-1,other,to,from);
// }

int cnt;

void f(int i,string from,string to,string other)
{
    if(i==0) return;
    f(i-1,from,other,to);
    cout << "移动圆盘" << i << "从" << from << "到" << to << '\n';
    ++cnt;
    f(i-1,other,to,from);
    
}

void hanoi(int n)
{
    f(n,"左","中","右") ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    hanoi(16);
    cout << "一共移动" << cnt << "次";
    return 0;
}