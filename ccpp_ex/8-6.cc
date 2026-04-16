#include<iostream>
#include<cstring>
typedef const char* pstr_t;
template<typename T>
T maxn(const T* num,unsigned int n)
{
    T max=num[0];
    for (unsigned int i=1;i<n;i++){
        if (num[i]>max) max=num[i];
    }
    return max;
}
template<> pstr_t maxn<pstr_t>(const pstr_t arr_pstr[],unsigned int n);

int main()
{
    const char* arrps[5]={"I","love","my","mum","!"};
    double arrdou[4]={1.3,4.5,6,2.0};
    std::cout << maxn(arrps,5) << std::endl;
    std::cout << maxn(arrdou,4) << std::endl;
    return 0;
}

template<> pstr_t maxn<pstr_t>(const pstr_t arr_pstr[],unsigned int n)
{
    pstr_t pmax=arr_pstr[0];
    auto max=strlen(arr_pstr[0]);
    for (unsigned int i=1;i<n;i++){
        if (strlen(arr_pstr[i])>max){
             max=strlen(arr_pstr[i]);
             pmax=arr_pstr[i];
        } 
    }
    return pmax;
}