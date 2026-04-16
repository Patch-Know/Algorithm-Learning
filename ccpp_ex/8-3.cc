#include <iostream>
#include <string>
#include <cctype>

void goup(std::string &str);

int main()
{
    using namespace std;
    string s1;
    cout << "Enter a string (q to quit): ";
    while (getline(cin, s1) && (s1[0] != 'q' || s1[1] != '\0'))
    {
        goup(s1);
        cout << s1 << endl;
        cout << "Next string (q to quit): ";
    }
    cout << "Bye.";
}

void goup(std::string &str)
{
    char *ps = &str[0];
    while (*ps)
    {
        *ps = toupper(*ps);
        ps++;
    }
}
