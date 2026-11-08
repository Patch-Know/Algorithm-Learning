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
    
    auto squares=std::views::iota(1)
        | std::views::transform([](int x){return x*x;})
        | std::views::take(10);
    for(auto x:squares) std::cout << x << std::endl;

}