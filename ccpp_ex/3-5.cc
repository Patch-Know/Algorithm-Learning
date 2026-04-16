#include<iostream>

using namespace std;

int main(){
    int world_population,us_population;
    cout<<"Enter the world's population: ";
    cin>>world_population;
    cin.get();
    cout<<"Enter the population of the US: ";
    cin>>us_population;
    cout<<"the population of the US is "<< double(us_population)/double(world_population)*100.0
    << "% of the world population"<<endl;
    return 0;
}