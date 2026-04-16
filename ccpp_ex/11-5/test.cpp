#include "stonewt.h"

int main()
{
    using namespace std;
    Stonewt a = 375;
    Stonewt b(35,12.6,Stonewt::PDF);
    Stonewt c(205);
    cout << a;
    b=b+a*0.05;
    b.setmode(Stonewt::PDF);
    cout << b;
    cout << a+b;
    cout << (a+b)*2<<b-a<<a-b;
    cout << b*3 <<a-c;
    return 0;
}