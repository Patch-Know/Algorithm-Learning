#include<iostream>
#include<numeric>
#include<ranges>
#include<vector>

int main()
{
    /* std::vector<int> vec(10);
    std::iota(vec.begin(),vec.end(),1);
    auto r=vec 
        | std::views::filter([](int x){return x%2==0;})
        | std::views::transform([](int x){return x*x;})
        | std::views::take(3);
    for(auto x:r){
        std::cout << x << std::endl;
    } */

    /*
    auto squares=std::views::iota(1)
        | std::views::transform([](int x){return x*x;})
        | std::views::stride(2)
        | std::views::take(10)
        | std::views::reverse;

    for(auto x:squares) std::cout << x << std::endl;
    */

    std::vector<int> x{1,2,3,4,5};
    std::vector<int> y{2,4,6,8,10};

    auto even_pairs = std::views::zip(x,y)
        | std::views::filter([](const auto &pair){return 
        std::get<0>(pair)%2==0 && 
        std::get<1>(pair)%2==0;});
    for(const auto &[a,b]:even_pairs){
        std::cout << "(" << a << ", "<< b << ") ";
    }
    std::cout<<std::endl;

    auto x_part = std::views::zip(std::views::iota(10),std::views::iota(3)| std::views::stride(2))
        | std::views::enumerate
        | std::views::values
        | std::views::values
        | std::views::take(7);
    for(const auto i:x_part) std::cout << i << std::endl;
    
    for(auto x:std::views::iota(2,66) | std::views::stride(3)) std::cout << x << ' ';
    }