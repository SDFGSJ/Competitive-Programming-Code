#include<bits/stdc++.h>
using namespace std;
long long f(long long a,long long b){
    return a*a*a+a*a*b+a*b*b+b*b*b;
}
int main(){
    long long N;
    scanf("%lld",&N);

    long long ans=LONG_LONG_MAX;
    for(long long a=0;a<=1e6;a++){
        long long L=-1,R=1e6;
        while(L+1<R){
            long long mid=L+(R-L)/2;
            if(f(a,mid)>=N){
                R=mid;
            }else{
                L=mid;
            }
        }
        ans=min(ans,f(a,R));
    }
    printf("%lld\n",ans);
    return 0;
}
/*
bs
enumerate a from 0 to 1e6
use bs to find the first b s.t. X>=N
*/