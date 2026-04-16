#include<iostream>

class complex0
{
private:
    double real;
    double imag;
public:
    complex0(){real=imag=0.0;}
    complex0(double r,double i){real=r;imag=i;}
    ~complex0(){};
    friend std::ostream & operator<< (std::ostream & os, const complex0 & cp);
    friend std::istream & operator>> (std::istream & is, complex0 & cp);
    complex0 operator+ (const complex0 & cp) const {return complex0(real+cp.real,imag+cp.imag);}
    complex0 operator- (const complex0 & cp) const {return complex0(real-cp.real,imag-cp.imag);}
    complex0 operator* (const complex0 & cp) const
    {
        return complex0(real*cp.real-imag*cp.imag,real*cp.imag+imag*cp.real);
    }
    complex0 operator* (const double x) const {return complex0(real*x,imag*x);}
    complex0 operator~ () const {return complex0(real,-imag);}
    friend complex0 operator* (const double x,const complex0 & cp) {return cp*x;}

};

std::ostream & operator<< (std::ostream & os, const complex0 & cp)
{
    os << "("<<cp.real<<","<<cp.imag<<"i)";
    return os;
}
std::istream & operator>> (std::istream & is, complex0 & cp)
{
    std::cout<<"real: ";
    if (is>>cp.real){
        std::cout<<"imaginary: ";
        is>>cp.imag;
    };
    return is;
}