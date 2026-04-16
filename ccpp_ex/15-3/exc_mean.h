// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(const std::string & what_arg) : logic_error(what_arg) {}
    void mesg();
};

inline void bad_hmean::mesg()
{   
    std::cout << "hmean(" << v1 << ", " << v2 <<"): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public std::logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(const std::string & what_arg) : logic_error(what_arg) {}

    const char * mesg();
};

inline const char * bad_gmean::mesg()
{  
    return "gmean() arguments should be >= 0\n";
}
