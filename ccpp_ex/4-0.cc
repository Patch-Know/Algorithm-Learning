#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

struct fish
{
    string variety;
    int weight;
    double length;
};

fish crap{"crap1",40,36.7};

enum Response{Yes=1,No=0,Maybe=2};

double ted=12.8;
double * pt=&ted;
//cout << *pt;

float treacle[10];
float* pr=treacle;


