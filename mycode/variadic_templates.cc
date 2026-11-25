#include<iostream>
#include<vector>
void print() { std::cout << '\n'; }

/* template<typename T,typename... Rest>
void print(T first,Rest... rest)
{
    std::cout << first << ' ';
    print(rest...); //recursion
} */

template<typename... Args>
void print(Args... args)
{
    ((std::cout << args << ' '),...);
    std::cout << '\n';
}

template <typename... Args>
void showCount(Args... args) {
    std::cout << "参数个数: " << sizeof...(args) << "\n";
    std::cout << "类型个数: " << sizeof...(Args) << "\n";
}

int main()
{
    print(1,2,"hello",'c');
    showCount(1,2,"hello",'c');
    
}