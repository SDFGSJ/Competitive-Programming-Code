#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    while(1){
        if(n%2!=0 && n%3!=0){
            break;
        }
        while(n%2==0){
            n/=2;
        }
        while(n%3==0){
            n/=3;
        }
    }
    //printf("n=%lld\n",n);
    if(n!=1){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}