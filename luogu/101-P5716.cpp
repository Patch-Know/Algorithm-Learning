#include<bits/stdc++.h>

using namespace std;

int rn(int y)//闰年函数
{
	return y%400==0||(y%4==0&&y%100!=0);
 } 
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//每个月的天数
int main(){
	int n,y;
	cin>>n>>y;
	if(rn(n))//如果是闰年，则二月有29天
		m[2]=29;
	cout<<m[y];//输出第y月，这里不需要特判，因为如果是闰年前面已经修改过天数了。
	
	return 0;
}