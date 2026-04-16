#include<iostream>
#include<cstring>

class BankAccount
{
private:
    char name[40];
    char acctnum[25];
    double banlance;
public:
    BankAccount(const char * client,const char * num,double bal = 0.0);
    ~BankAccount();
    void show() const;
    void deposit(double cash);
    void withdraw(double cash);

};

BankAccount::BankAccount(const char * client,const char * num,double bal)
{
    std::strncpy(name,client,40-1);
    name[39]='\0';
    std::strncpy(acctnum,num,25-1);
    acctnum[24]='\0';
    banlance=bal;
}

BankAccount::~BankAccount()
{
}

void BankAccount::show() const
{
    using namespace std;
    cout << "Name: " << name <<endl
    << "Account number: " << acctnum <<endl
    << "Balance: " << banlance <<endl;
}

void BankAccount::deposit(double cash)
{
    if (cash>0)banlance+=cash;
    else std::cout<< "Deposit failed."<<std::endl;
}

void BankAccount::withdraw(double cash)
{
    if (cash <= banlance) banlance-=cash;
    else std::cout<< "Withdraw failed."<<std::endl;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    BankAccount ac0("hehedaren","021200",200);
    ac0.show();
    int ch;
    double cash=0;
    cout<< "Enter your choice (0 to deposit,1 to withdraw,else to quit): ";
    while (cin>>ch && (ch==0 || ch==1))
    {
        while (getchar()!='\n') continue;
        switch (ch)
        {
        case 0:
            cout << "<Deposit Mode>" <<endl << "Enter your cash: ";
            if(cin>>cash) ac0.deposit(cash);
            else cin.clear();
            while (getchar()!='\n') continue;
            ac0.show();
            break;
        case 1:
            cout << "<Withdraw Mode>" <<endl << "Enter your cash: ";
            if(cin>>cash) ac0.withdraw(cash);
            else cin.clear();
            while (getchar()!='\n') continue;
            ac0.show();
            break;
        }
        cout<< "Enter your choice (0 to deposit,1 to withdraw,else to quit): ";

    }
    cout << "Bye!" <<endl;

}