#include <iostream>
#include <cstring>   
using namespace std;

class CString
{
    char *str;    // 字符串
public:
    CString();                      // 默认构造函数
    CString(const char s[]);        // 带参构造函数
    CString(CString &t);            // 拷贝构造函数
    ~CString();                     // 析构函数
    int Set(const char s[]);        // 将str重新赋值为s，返回其长度
    void Print();                   // 输出
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

int main() {
 char s0[100], s1[100];
 cin >> s0 >> s1;
 CString cs0(s0),cs1(cs0);
 cs0.Set(s1);
 cs0.Print();
 cs1.Print();
 return 0;
}