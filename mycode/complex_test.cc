#include<iostream>
#include<complex>

int main()
{
    //创建两个复数
    std::complex<double> c1(5.0,3.0);
    std::complex<double> c2(2.0,-4.0);

    //输出复数
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    
    //复数加法
    std::complex<double> sum{c1+c2};
    std::cout << "sum: " << sum << std::endl;
    
    //复数的共轭
    std::complex<double> conjugate{std::conj(c1)};
    std::cout << "Conjugate of c1: " << conjugate << std::endl;

    //复数的模
    std::cout << "Modulus of c1: " << std::abs(c1) << std::endl;
    
    //复数的辐角(弧度制)
    std::cout << "Argument of c1: " << std::arg(c1) << std::endl;
}