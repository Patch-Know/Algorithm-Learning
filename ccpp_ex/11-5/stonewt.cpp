// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs,Mode md)
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode=md;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs,Mode md)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
    mode=md;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode=ST;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
// void Stonewt::show_stn() const
// {
//     cout << stone << " stone, " << pds_left << " pounds\n";
// }

// show weight in pounds
// void Stonewt::show_lbs() const
// {
//     cout << pounds << " pounds\n";
// }

std::ostream & operator<< (std::ostream & os,const Stonewt & s)
{
    if (s.mode==Stonewt::ST) os<< s.stone << " stones, " << s.pds_left << " pounds\n";
    else if (s.mode==Stonewt::PDI) os << (int)s.pounds << " pounds\n";
    else os<< s.pounds << " pounds\n";
    return os;
}
    
Stonewt  Stonewt::operator+ (const Stonewt & s) const
{
    Stonewt temp(pounds+s.pounds);
    return temp; 
}

Stonewt  Stonewt::operator- (const Stonewt & s) const
{
    double left = pounds > s.pounds ? pounds -s.pounds : 0 ;
    Stonewt temp(left);
    return temp;
}

Stonewt  Stonewt::operator* (const double x) const
{
    Stonewt temp(pounds*x);
    return temp;
}
