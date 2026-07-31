#include <iostream>
#include <cstring>
using namespace std;

class CString
{
protected:
    char *str;
public:
    CString();
    CString(const char s[]);
    CString(CString &t);
    ~CString();
    int Set(const char s[]);
    void Print();
};

CString::CString()
{
    str = new char[1];
    str[0] = '\0';
}

CString::CString(const char s[])
{
    if (s == NULL)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
}

CString::CString(CString &t)
{
    int len = strlen(t.str);
    str = new char[len + 1];
    strcpy(str, t.str);
}

CString::~CString()
{
    delete[] str;
}

int CString::Set(const char s[])
{
    delete[] str;
    if (s == NULL)
    {
        str = new char[1];
        str[0] = '\0';
        return 0;
    }
    int len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return len;
}

void CString::Print()
{
    cout << str;
}

class CString2 : public CString
{
public:
    CString2();
    CString2(const char s[]);
    CString2(CString2 &t);
    CString2 &Cat(CString2 &t);
    int Cmp(CString2 &t);
};

CString2::CString2() : CString() {}

CString2::CString2(const char s[]) : CString(s) {}

CString2::CString2(CString2 &t) : CString(t) {}

CString2 &CString2::Cat(CString2 &t)
{
    int len1 = strlen(str);
    int len2 = strlen(t.str);
    char *newStr = new char[len1 + len2 + 1];
    strcpy(newStr, str);
    strcat(newStr, t.str);
    delete[] str;
    str = newStr;
    return *this;
}

int CString2::Cmp(CString2 &t)
{
    return strcmp(str, t.str);
}

int main() {
 char s0[100], s1[100];
 cin >> s0 >> s1;
 CString2 cs0(s0),cs1(cs0);
 cs0.Set(s1);
 cout << cs0.Cmp(cs1) << endl;
 CString2 &t=cs0.Cat(cs1);
 t.Print();
 return 0;
}