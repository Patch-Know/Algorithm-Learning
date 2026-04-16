#include<iostream>
#include"golf.h"
int main()
{
    const int Num = 10;
    golf gfarr[Num];
    
    // {
    //     int i=0;
    //     while (i<Num && gfarr[i].setgolf())
    //     {
    //         i++;
    //     }
    // }
    for (int i = 0; i < Num; i++)
    {
        if (!gfarr[i].setgolf()) break;
    }
    for (int i = 0; i < Num && !gfarr[i].is_empty(); i++)
    {
        gfarr[i].showgolf();
    }
    
    return 0;
}