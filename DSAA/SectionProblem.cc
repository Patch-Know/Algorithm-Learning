#include<iostream>
#include<ctime>
#include<random>
#include<algorithm>

using namespace std;

int Lomuto_partition(int a[],int l,int r);
void swap(int & a,int & b)
{
    int temp=a;
    a=b;
    b=temp;
}

const int N = 100;

int main()
{
    int a[N];
    for(int i=0;i<N;i++) a[i]=i+1;
    std::random_device rd; //目前应该这样使用
    std::mt19937 gen(rd());
    shuffle(a,a+N,gen); //记得包含algorithm
    int k;
    cin>>k;
    int left=0,right=N-1;
    int s;
    while((s=Lomuto_partition(a,left,right))!=k-1){ //类似于二分，通过不断划分，找到划分后k-1位置上的数，即第k大的数
        if(s<k-1){
            left=s+1;
        }else{
            right=s-1;
        }
    }
    cout<<a[s]<<endl;

    return 0;
}

int Lomuto_partition(int a[],int l,int r) //根据l位置上的数将区间【l，r】进行划分，并返回l数的新位置
{
    int target=a[l];
    int j=l;
    for(int i=l+1;i<=r;i++){
        if(a[i]<target){
            swap(a[++j],a[i]);
        }                                     
    }
    swap(a[l],a[j]);
    return j;
}
