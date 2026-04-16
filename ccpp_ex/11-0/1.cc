class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt(double lbs);          // construct from double pounds
    Stonewt(int stn, double lbs); // construct from stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format
// conversion functions
    operator int() const;
    operator double() const;
    Stonewt operator* (double x) const;
};

// Stonewt Stonewt::operator* (double x) const
// {
//     Stonewt temp;
//     temp.pounds = (stone*14+pds_left)*x;
//     temp.stone = (int)temp.pounds / Lbs_per_stn;
//     temp.pds_left = temp.pounds - temp.stone*Lbs_per_stn;
//     return temp;
// }

Stonewt Stonewt::operator* (double x) const
{
    return Stonewt(pounds*x);
}