#include<bits/stdc++.h>
using namespace std;
long long cnt[40];
long long mypow(long long a, long long b){
    long long res=1;
    while(b){
        if(b&1){
            res*=a;
        }
        b>>=1;
        a*=a;
    }
    return res;
}
int main(){
    long long n;
    scanf("%lld",&n);

    cnt[1]=10, cnt[2]=cnt[1]+9;
    for(int i=3;i<=36;i++){
        cnt[i]=cnt[i-1]+9ll*mypow(10,(i+1)/2-1);
    }
    for(int i=1;i<=36;i++){
        printf("%lld\n",cnt[i]);
    }
    return 0;
}