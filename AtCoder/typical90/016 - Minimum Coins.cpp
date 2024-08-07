#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,c;
    scanf("%lld%lld%lld%lld",&n,&a,&b,&c);

    long long ans=1e9;
    for(int i=0;i<10000;i++){
        for(int j=0;i+j<10000;j++){
            long long remain=n-a*i-b*j;
            if(remain<0){
                break;
            }
            if(remain%c==0){
                ans=min(ans,i+j+remain/c);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}