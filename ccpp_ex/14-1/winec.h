#include <iostream>
#include <string>
#include <iomanip>
#include <valarray>
template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
    Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{
    return a;
}
template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{
    return b;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine
{
private:
    std::string name;
    PairArray info;
public:
    Wine(/* args */);
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);
    ~Wine();
    void Getbottles();
    std::string & Lable() {return name; }
    int Sum() const {int sum=0;for (int x : info.second()) sum +=x;return sum;}
    void Show() const;
};

Wine::Wine(/* args */)
{
}

Wine::~Wine()
{
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) :name(l)
{
    ArrayInt years(y),bottles(y);
    for (int i = 0; i < y; i++)
    {
        years[i]=yr[i];
        bottles[i]=bot[i];
    }
    info=PairArray(years,bottles);
}

Wine::Wine(const char * l, int y) : name(l),info(ArrayInt(y),ArrayInt(y))
{
}

void Wine::Getbottles()
{
    using std::cout,std::cin,std::endl;
    int years = info.first().size();
    if(years>0)
    cout << "Enter " << name <<" data for " << years << "year(s):" <<endl;
    int tmpyr,tmpbot;
    for (int i = 0; i < years; i++)
    {
        cout << "Enter year: ";
        cin >> tmpyr;
        cout << "Enter bottles for that year: ";
        cin >> tmpbot;
        info.first()[i]=tmpyr;
        info.second()[i]=tmpbot;
    }
    
}

void Wine::Show() const
{
    using std::cout,std::endl;
    cout << "Wine: " << name <<endl;
    int years =  info.first().size();
    for (int i = 0; i < years; i++)
    {
        cout << std::setw(12) << std::right << info.first()[i];
        cout << '\t' << std::left << info.second()[i] << endl;
    }
    
}
