#include<iostream>
#include<cmath>
using namespace std;

class Triangle{
private:
    double a; //边长1
    double b; //边长2
    double c; //边长3
public:
    Triangle(double x,double y,double z):a(x),b(y),c(z){}
    bool IfTriangle()
    {
        if(a+b<=c || a+c<=b || b+c<=a) return false;
        return true;
    }
    double GetPerimeter(){return a+b+c;}
    double GetArea()
    {
        double s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    Triangle t(a,b,c);
    if(t.IfTriangle()){
        cout << "周长=" << t.GetPerimeter()<<endl;
        cout << "面积=" << t.GetArea() << endl;
    }else cout << "不能围成三角形" << endl;
    return 0;
}