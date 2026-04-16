#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,ap,bp,cp,n;
    int i;
    cin>>n>>a>>ap>>b>>bp>>c>>cp;
    int max=(n/a+1)*ap;
    // for(i=0;i<=n;i++){
    //     if(i*a>=n){
    //         if(i*ap<max) max=i*ap;
    //         break;
    //     }
    //     for(j=0;j<=n;j++){
    //         if(i*a+j*b>=n){
    //             if(i*ap+j*bp<max) max=i*ap+j*bp;
    //             break;
    //         }
    //         for(k=0;k<=n;k++){
    //             if(i*a+j*b+k*c>=n){
    //                 if(i*ap+j*bp+k*cp<max) max=i*ap+j*bp+k*cp;
    //                 break;
    //             }   
    //         }

    //     }

    // }
    for(i=0;i<=n;i++){
        if(i*a>=n){
            if(i*ap<max) max=i*ap;
            break;
        }
    }    
    for(i=0;i<=n;i++){
        if(i*b>=n){
            if(i*bp<max) max=i*bp;
            break;
        }
    }
    for(i=0;i<=n;i++){
        if(i*c>=n){
            if(i*cp<max) max=i*cp;
            break;
        }
    }         
    cout<<max;

    return 0;
}