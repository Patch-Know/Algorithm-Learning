// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
public:
    enum Mode {ST,PDI,PDF};
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    Mode mode;
    int stone;                     // whole stones
    double pds_left;              // fractional pounds
    double pounds;               // entire weight in pounds
public:
    Stonewt(double lbs,Mode md=ST);          // constructor for double pounds
    Stonewt(int stn, double lbs,Mode md=ST); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void setmode(Mode md=ST){mode=md;}
    // void show_lbs() const;        // show weight in pounds format
    // void show_stn() const;        // show weight in stone format
    friend std::ostream & operator<< (std::ostream & os,const Stonewt & s);
    Stonewt  operator+ (const Stonewt & s) const;
    Stonewt  operator- (const Stonewt & s) const;
    Stonewt  operator* (const double x) const;
    friend Stonewt  operator* (const double x,const Stonewt & s){return s*x;}

};
#endif
