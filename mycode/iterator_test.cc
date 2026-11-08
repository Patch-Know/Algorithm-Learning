#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> v;
    std::fill_n(std::back_inserter(v),3,100);
    std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout," "));
}