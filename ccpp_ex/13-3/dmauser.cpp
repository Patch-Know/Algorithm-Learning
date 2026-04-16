#include<iostream>
#include<string>
#include<cstring>
#include"dma.h"

const int DMAs = 1;

int main()
{
    using std::cin,std::cout,std::endl,std::getline;
    PureDMA *pdmas[DMAs];
    std::string templable,tempcolor,tempstyle;
    int tempnum;
    char kind;
    for (int i = 0; i < DMAs; i++)
    {
        cout << "Enter a label: ";
        getline(cin,templable);
        cout << "Enter a rating: ";
        cin >> tempnum;
        cout << "Enter 1 for Base , 2 for Lack ,3 for Has: ";
        while (cin >> kind && (std::strchr("123",kind)==nullptr)) cout << "Please enter 1 or 2 or 3: ";
        cin.get();
        switch (kind)
        {
        case '1':
            pdmas[i] = new baseDMA(templable.c_str(),tempnum);
            break;
        case '2':
            cout << "Enter a color: ";
            getline(cin,tempcolor);
            pdmas[i] = new lacksDMA(tempcolor.c_str(),templable.c_str(),tempnum);
            break;
        case '3':
            cout << "Enter a style: ";
            getline(cin,tempstyle);
            pdmas[i] = new hasDMA(tempstyle.c_str(),templable.c_str(),tempnum);
            break;
        }
        while (cin.get()!= '\n') continue;
    }
    cout << endl;
    for (int i = 0; i < DMAs; i++)
    {
        pdmas[i]->Sayself();
        pdmas[i]->Show();
        //cout << *pdmas[i];
        cout  <<endl;
    }
    for (int i = 0; i < DMAs; i++)
    {
        
        delete pdmas[i];
    }
    
    return 0;
}