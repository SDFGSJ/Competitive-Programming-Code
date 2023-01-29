#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k,ans;
    scanf("%lld%lld",&n,&k);
    if(n%2==1){
        if(k<=(n+1)/2){ //odd
            ans=1+(k-1)*2;
        }else{  //even
            k-=(n+1)/2;
            ans=2*k;
        }
    }else{
        if(k<=n/2){
            ans=1+(k-1)*2;
        }else{
            k-=n/2;
            ans=2*k;
        }
    }
    printf("%lld\n",ans);
    return 0;
}