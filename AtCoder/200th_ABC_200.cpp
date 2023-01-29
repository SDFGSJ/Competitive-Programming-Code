#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    int k,cnt=0;
    scanf("%lld%d",&n,&k);
    while(cnt<k){
        if(n%200==0){
            n/=200;
        }else{
            n=n*1000+200;
        }
        cnt++;
    }
    printf("%lld",n);
    return 0;
}