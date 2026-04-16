#include "emp.h"

using namespace std;

inline void clear()
{while(cin.get()!='\n') continue;}

abstr_emp::abstr_emp() : fname("none"),lname("none"),job("none")
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
: fname(fn),lname(ln),job(j)
{
}

void abstr_emp::ShowAll() const
{
    cout << "Name: " << fname <<", " << lname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
    string temp;
    cout << "Enter your fist & last name: ";
    cin >> fname >> lname;
    cout << "Enter your job: ";
    cin >> job;
    clear();
}

std::ostream & operator<<(std::ostream & os,const abstr_emp & e)
{
    os << "Name: " << e.fname <<", " << e.lname << endl;
    return os;
}

abstr_emp::~abstr_emp(){}

employee::employee() : abstr_emp()
{}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn,ln,j)
{}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll() 
{
    abstr_emp::SetAll();
}

manager::manager() : abstr_emp(),inchargeof(0)
{}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
: abstr_emp(fn,ln,j),inchargeof(ico)
{}

manager::manager(const abstr_emp & e, int ico)
: abstr_emp(e),inchargeof(ico)
{}

manager::manager(const manager & m) : abstr_emp(m),inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "The number of emps managed: " << inchargeof << endl;
}

void manager::SetAll() 
{
    abstr_emp::SetAll();
    cout << "Enter the number of emps managed: ";
    cin >> inchargeof;
    clear();
}

fink::fink() : abstr_emp(),reportsto("none")
{}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
:abstr_emp(fn,ln,j),reportsto(rpo) 
{}

fink::fink(const abstr_emp & e, const std::string & rpo)
:abstr_emp(e),reportsto(rpo) 
{}

fink::fink(const fink & e)
:abstr_emp(e),reportsto(e.reportsto) 
{}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll() 
{
    abstr_emp::SetAll();
    cout << "Enter whom reports to: ";
    cin >> reportsto;
    clear();
}

//highfink

highfink::highfink() : abstr_emp(),manager(),fink()
{}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
:abstr_emp(fn,ln,j),fink(fn,ln,j,rpo),manager(fn,ln,j,ico) 
{}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
:abstr_emp(e),fink(e,rpo),manager(e,ico) 
{}

highfink::highfink(const fink & f, int ico)
:abstr_emp(f),fink(f),manager(f,ico)
{}

highfink::highfink(const manager & m, const std::string & rpo)
:abstr_emp(m),fink(m,rpo),manager(m) 
{}

highfink::highfink(const highfink & h) : abstr_emp(h),fink(h),manager(h)
{}


void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "The number of emps managed: " << InChargeOf() << endl;
    cout << "Reports to: " << ReportsTo() << endl;
}

void highfink::SetAll() 
{
    abstr_emp::SetAll();
    cout << "Enter the number of emps managed: ";
    cin >> InChargeOf();
    cout << "Enter whom reports to: ";
    cin >> ReportsTo();
    clear();
}