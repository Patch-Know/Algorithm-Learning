#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,temp;
    int n,op;
    int a,b;
    cin >> n;
    cin >> s;
    for(int i = 0;i<n;i++){
        cin >> op;
        switch(op){
            case 1: cin >> temp;
                    s.append(temp);
                    cout << s << endl;
                    break;
            case 2: cin >> a >> b;
                    s=s.substr(a,b);
                    cout << s << endl;
                    break;
            case 3: cin >> a;
                    cin >> temp;
                    s.insert(a,temp);
                    cout << s << endl;
                    break;
            case 4: cin >> temp;
                    cout << ((b=s.find(temp))>=0 ? b : -1) << endl;
                    break;
        }
    }
    return 0;
}