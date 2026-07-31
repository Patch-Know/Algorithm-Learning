#include <iostream>
#include <iomanip>
using namespace std;
class Rectangle    //定义类，名称是Rectangle
{
private:
	double a;  	//定义成员数据: 长
	double b;       //定义成员数据: 宽
public:
	Rectangle(double x,double y)  //定义构造函数
	{
		a=x;b=y;
	}
	void Set(double x, double y)  //定义成员函数，设置矩形的长、宽
	{
	    a=x;b=y;
	}
	double GetPerimeter()		//定义成员函数，求矩形的周长
	{ 
		return (a+b)*2;
	}
	double GetArea()		//定义成员函数，求矩形的面积
	{ 
		return a*b;
    }
};

int main()
{
    Rectangle t1(1.1,2.2),t2(3.3,4.4);
    cout << "Perimeter=" << fixed << setprecision(1) << t1.GetPerimeter() <<",Area=" << setprecision(2) << t1.GetArea()<< endl;
    cout << "Perimeter=" << fixed << setprecision(1) << t2.GetPerimeter() <<",Area=" << setprecision(2) << t2.GetArea()<< endl;

    return 0;
}