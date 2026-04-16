#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;

vector<int> Lotto(int total,int num);

int main()
{
    vector<int> winners;
    winners = Lotto(51,19);
    for(int x:winners) cout << x << ",";
    return 0;
}

vector<int> Lotto(int total,int num)
{
    vector<int> temp(total);
    for (int i = 0 ; i < total ; i++) temp[i]=i;
    std::random_device rd; //目前应该这样使用
    std::mt19937 gen(rd());
    shuffle(temp.begin(),temp.end(),gen);
    return vector<int> (temp.begin(),temp.begin()+num);
}