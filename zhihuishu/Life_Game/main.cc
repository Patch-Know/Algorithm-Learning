#include"utility.h"
#include"life.h"

int main()
{
    Life config;
    instructions();
    config.init();
    config.print();
    cout << "Continue viewing new generations?" << endl;
    while(user_says_yes()){
        config.update();
        config.print();
        cout << "Continue viewing new generations?" << endl;
    }
}

