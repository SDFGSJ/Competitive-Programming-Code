#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    long long ans=0;
    for(int i=1;i<=n;i++){
        long long k=n/i;
        ans+=1ll*i*k*(k+1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
for each divisor i, see how many nums that have this divisor i
ex.
i=1 appears in 1,2,...,n => add 1+2+..+k = k*(k+1)/2 to ans
i=2 appears in 2,4,...,2k => add 2+4+...+2k = 2*k*(k+1)/2 to ans
*/