#include<bits/stdc++.h>
using namespace std;
bool valid(long long num,long long N,long long i){
    return N/num>=N/i;
}
int main(){
    long long N;
    scanf("%lld",&N);

    long long ans=0;
    for(long long i=1;i<=N;){
        long long L=i,R=N+1;
        while(L+1<R){
            long long mid=L+(R-L)/2;
            if(valid(mid,N,i)){
                L=mid;
            }else{
                R=mid;
            }
        }
        ans+=(N/i)*(L-i+1);
        i=R;
    }
    printf("%lld\n",ans);
    return 0;
}