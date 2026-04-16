#include <iostream>
#include <cstring>
const int Max = 30;

struct CandyBar
{
    char name[30];
    double weight;
    int heat;
};

void set(CandyBar &ct, const char *name = "Millennium Munch", const double weight = 2.85, const int heat = 300);
void show(const CandyBar &ct);

int main()
{
    CandyBar family;
    set(family, "WANG SHIHONG", 60);
    show(family);
    return 0;
}

void set(CandyBar &ct, const char *name, const double weight, const int heat)
{
    strncpy(ct.name, name, Max);
    ct.weight = weight;
    ct.heat = heat;
}

void show(const CandyBar &ct)
{
    using namespace std;
    cout << "Brand: " << ct.name << endl
         << "Weight: " << ct.weight << endl
         << "Heat: " << ct.heat << endl;
}