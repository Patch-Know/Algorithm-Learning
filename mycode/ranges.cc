#include<iostream>
#include<ranges>
#include<vector>
int main()
{
    std::vector<int> vec{1,2,3,4,5};
    auto r=vec | std::views::filter([](int x){return x%2==0;});
    for(auto x:r){
        std::cout << x << std::endl;
    }

}