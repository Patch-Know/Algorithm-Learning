#include<iostream>
#include "classic.h"
using namespace std;

void Bravo(const CD & disk) {disk.Report();}

int main()
{
    CD c1("Beatles","Capitol", 14 ,35.5);
    Classic c2  = Classic("Piano Sonata in B flat, Fantasia in C","Alfred Brendel","Philips",2, 57.17);
    CD * pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();

    cout << "Using type cd *  pointer to objects:\n";
    pcd ->Report();

    cout << "Calling a function with a CD reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    
    return 0;
}