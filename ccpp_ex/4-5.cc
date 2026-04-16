#include<iostream>
#include<string>

struct CandyBar
{
    std::string brand;
    double weight;
    int calorie; 
};

int main(){
    using namespace std;
    CandyBar snack{"Mocha Munch",2.3,350};
    //CandyBar candy[3];
    //CandyBar* pc=new CandyBar[3];
    cout<<"Brand:  \t"<<snack.brand<<endl
    <<"Weight:  \t"<<snack.weight<<endl
    <<"Calorie:\t" <<snack.calorie<<endl;
    return 0;
}
