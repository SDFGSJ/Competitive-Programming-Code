#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,i;
    scanf("%lld",&t);
    while(t--){
        long long n,s,d,cnt=0,ans=0;
        scanf("%lld%lld%lld",&n,&s,&d);
        long long Max=(n-1)*s;
        /*for(i=0;i<=(n-1)*s;i+=s){
            ans += ((min(i+d,Max)-i) / s);
        }*/
        /*i=0;
        while(i+d<Max){
            i+=s;
            cnt++;
        }*/
        //printf("cnt=%d\n",cnt);
        printf("cnt=%d\n",max(0ll,n-(d/s)));
        ans=max(0ll,n-(d/s)) * (d/s) + min(n-1,(d/s)-1)*min(n,d/s) / 2;
        printf("%lld\n",ans);
    }
    return 0;
}