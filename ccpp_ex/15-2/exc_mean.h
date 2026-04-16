// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>
#include <string>

class bad_base : public std::logic_error
{
    protected:
        std::string sh = "a == -b";
        std::string sg = "a < 0 || b < 0";
    public:
        bad_base(const std::string & what_arg) : logic_error(what_arg) {}
        virtual void Show() const = 0;
};

class bad_hmean : public bad_base
{
private:
    double v1;
    double v2;
public:
    bad_hmean(const std::string & what_arg) : bad_base(what_arg) {}
    virtual void Show() const;
    void mesg();
};

inline void bad_hmean::Show() const
{   
    std::cout << "Exception function: " << what() << " , Error: " << bad_base::sh;
}

inline void bad_hmean::mesg()
{   
    std::cout << "hmean(" << v1 << ", " << v2 <<"): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public bad_base
{
public:
    double v1;
    double v2;
    bad_gmean(const std::string & what_arg) : bad_base(what_arg) {}
    virtual void Show() const;
    const char * mesg();
};

inline const char * bad_gmean::mesg()
{  
    return "gmean() arguments should be >= 0\n";
}

inline void bad_gmean::Show() const
{   
    std::cout << "Exception function: " << what() << " , Error: " << bad_base::sg;
}