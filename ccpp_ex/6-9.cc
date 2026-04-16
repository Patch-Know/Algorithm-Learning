#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
struct donation
{
    string name;
    double fund;   
};

int main()
{
    int n;
    ifstream inFile;
    inFile.open("donainfo");
    if (!inFile.is_open()) exit(EXIT_FAILURE);
    //cout<<"Enter number: ";
    inFile>>n;
    int cng=0,cnp=0;
    if (n>0){
        donation* pd=new donation[n];
        for (int i=0;i<n;i++){
            inFile.get();
            //cout<<"Enter name: ";
            getline(inFile,pd[i].name);
            //cout<<"Enter fund: ";
            while (!(inFile>>pd[i].fund)){
                inFile.clear();
                while(getchar()!='\n') continue;
                //cout<<"Enter fund: ";
            }
            if (pd[i].fund>10000) cng++;
            else cnp++;
        }
        cout<<"Grand Patrons:\n";
        if (cng){
            for (int i=0;i<n;i++){
                if (pd[i].fund>10000){
                    cout<<pd[i].name<<endl<<pd[i].fund<<endl;
                }
            }
        }else cout<<"none"<<endl;
        cout<<"Patrons:\n";
        if (cnp){
            for (int i=0;i<n;i++){
                if (!(pd[i].fund>10000)){
                    cout<<pd[i].name<<endl<<pd[i].fund<<endl;
                }
            }
        }else cout<<"none"<<endl;

    }
    inFile.close();
    return 0;
}