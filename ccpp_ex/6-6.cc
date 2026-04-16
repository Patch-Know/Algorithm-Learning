#include<iostream>
#include<string>
using namespace std;
struct donation
{
    string name;
    double fund;   
};

int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cin.get();
    int cng=0,cnp=0;
    if (n>0){
        donation* pd=new donation[n];
        for (int i=0;i<n;i++){
            cout<<"Enter name: ";
            getline(cin,pd[i].name);
            cout<<"Enter fund: ";
            while (!(cin>>pd[i].fund)){
                cin.clear();
                while(getchar()!='\n') continue;
                cout<<"Enter fund: ";
            }
            cin.get();
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
    return 0;
}