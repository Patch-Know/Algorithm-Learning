#include "winec2.h"

int main()
{
    using std::cin,std::cout,std::endl;
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab,50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab,yrs);
    holding.Getbottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = {1993,1995,1998};
    int b[YRS] = {40,60,72};
    Wine more("Gushing Grape Red",YRS,y,b);
    more.Show();
    cout << "Total bottles for " << more.Lable()
         << ": " <<more.Sum() << endl;
    cout << "Bye!\n";

    return 0;
}