// const int Len = 40;
// struct golf
// {
//     char fullname[Len];
//     int handicap;
// };

// void setgolf(golf & g,const char * name , int hc);

// int setgolf(golf & g);

// void handicap(golf & g,int hc);

// void showgolf(const golf & g);
#include <cstring>
class golf
{
private:
    enum
    {
        Len = 40
    };
    char fullname[Len];
    int handicap;

public:
    golf(const char *name, int hc = 0)
    {
        std::strncpy(fullname, name, Len - 1);
        fullname[Len - 1] = '\0';
        handicap = hc;
    };
    golf()
    {
    };
    void showgolf() const;
    void sethandicap(int hc);
    int setgolf();
    bool is_empty() const 
    {
        if (fullname[0]=='\0') return true;
        else return false;
    }
};
