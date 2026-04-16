#include<iostream>

template<typename T>
T max5(const T* num)
{
    T max=num[0];
    for (int i=1;i<5;i++){
        if (num[i]>max) max=num[i];
    }
    return max;
}

int main()
{
    int arr_int[5]{1,7,8,9};
    double arr_double[5]={3,6,8,3,4};
    std::cout<< "intmax = " <<max5(arr_int)<<std::endl
    <<"doublemax = " << max5(arr_double)<<std::endl;
    return 0;
}