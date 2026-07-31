#include<iostream>
#include<cmath>
using namespace std;

class CBall
{
	double r;    //水球的半径
public:
	CBall():r(0){};    //构造函数,水球的半径=0
	CBall(double r):r(r){};   //构造函数,水球的半径=r
	  //拷贝构造函数
	CBall Add(const CBall &t){return CBall(pow(r*r*r+t.r*t.r*t.r,1.0/3.0));}; //实现两个水球融合，返回融合后的水球
	double GetR(){return r;};   //返回水球半径
};

int main() {
	CBall b0, b1(5),b2;
	double r;
	cin >> r;
	b0 = CBall(r);
	b2=b1.Add(b0);
	printf("%.2f",b2.GetR());
	return 0;
}