#include<bits/stdc++.h>
using namespace std;
long long a[300010],prefix[300010];
const long long mod=1e8;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }

    long long ans=0;
    for(int i=1;i<=n-1;i++){
        int idx=lower_bound(a+1+i,a+1+n,mod-a[i])-a;  //1-indexed
        ans+=a[i]*(n-i);
        ans+=prefix[idx-1]-prefix[i];
        ans+=prefix[n]-prefix[idx-1]-mod*(n-idx+1);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
for every a[i], let idx = the index of the first number s.t. a[i] + a[idx] >= 1e8
so a[idx-1] is the last number s.t. a[i] + a[idx-1] < 1e8
then the problem divides into 2 parts(a+b<1e8 & a+b>=1e8)
a[i] has (n-i) additions
(1)a+b<1e8
a[i] + a[k] < 1e8 (i+1 <= k <= idx-1)
so the sum from a[i+1] to a[idx-1] = prefix[idx-1]-prefix[i]

(2)a+b>=1e8
a[i] + a[k] >= 1e8 (idx <= k <= n)
so the sum from a[idx] to a[n] = prefix[n]-prefix[idx-1]
and we need to minus (n-idx+1) 1e8's
*/