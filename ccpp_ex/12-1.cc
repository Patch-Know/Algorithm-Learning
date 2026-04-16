#include<iostream>
#include<cstring>

class Cow
{
private:
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const;
};

Cow::Cow()
{
    name[0]='\0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    std::strcpy(name,nm);
    int len = std::strlen(ho);
    hobby = new char[len+1];
    std::strcpy(hobby,ho);
    weight =wt;
}

Cow::Cow(const Cow & c)
{
    std::strcpy(name,c.name);
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    std::strcpy(hobby,c.hobby);
    weight = c.weight;
}


Cow::~Cow()
{
    delete [] hobby;
    std::cout<<"Bye!\n";
}

Cow & Cow::operator=(const Cow & c)
{
    if (this == &c) return * this;
    std::strcpy(name,c.name);
    delete [] hobby;
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    std::strcpy(hobby,c.hobby);
    weight = c.weight;
    return * this;
}

void Cow::ShowCow() const
{
    using std::cout;
    using std::endl;
    cout << "class Cow's information:\n";
    cout << "name: " << name <<endl
         << "hobby: " << hobby <<endl
         << "weight: " << weight <<endl;
}

int main()
{
    {
    Cow c1;
    Cow c2("hehedaren","football",70);
    Cow c3= c2;
    Cow c4("mum","computer",65.6);
    c1 =c4;
    c1.ShowCow();
    c2.ShowCow();
    c3.ShowCow();
    c4.ShowCow();
    std::cin.get();
    }
    return 0;
}