#include<iostream>
#include<valarray>
#include<cmath>

int main()
{
    std::valarray<double> va(5);
    va={1,2,3,4,5};
    for(auto i:va) std::cout << i << ' ';
    std::cout << std::endl;
    
    std::valarray<double> squares{va*va}; //平方
    std::valarray<double> roots{std::sqrt(va)}; //开方
    
    std::cout << "Squares: ";
    for(auto i:squares) std::cout << i << ' ';
    std::cout << std::endl;
    
    std::cout << "Roots: ";
    for(auto i:roots) std::cout << i << ' ';
    std::cout << std::endl;
    
    
}