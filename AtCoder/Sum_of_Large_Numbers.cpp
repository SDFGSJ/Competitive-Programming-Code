#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    long long ans=0;
    for(long long i=k;i<=n+1;i++){
        ans=(ans+i*(n-i+1)+1)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
Consider the lower/upper bound of the possible sum when choosing k numbers
min sum = 0+1+...+(k-1) = k(k-1)/2, max sum = (n-k+1)+...+(n-1)+n = k(2n-k+1)/2
there are k(n-k+1)+1 nums between them
ans=sum(i(n-i+1)+1) for i in [k, n+1]
*/