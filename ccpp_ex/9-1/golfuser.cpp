#include<iostream>
#include"golf.h"
int main()
{
    const int Num = 10;
    golf gfarr[Num];
    for (int i = 0; i < Num; i++)
    {
        setgolf(gfarr[i],"None",0);
    }
    {
        int i=0;
        while (i<Num && setgolf(gfarr[i]))
        {
            i++;
        }
    }

    for (int i = 0; i < Num && gfarr[i].fullname[0]!='\0'; i++)
    {
        showgolf(gfarr[i]);
    }
    
    return 0;
}