#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long pre[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=(pre[n]-pre[i])-1ll*a[i]*(n-i);
    }
    printf("%lld\n",ans);
}
/*
prefix sum
since a number will calc the abs diff with other numbers exactly once
so we can calc the ans after sorting a[]

consider Ai after the array is sorted
|An-Ai| + |A_(n-1)-Ai| + ... + |A_(i+1)-Ai|
= (An + ... + A_(i+1)) - Ai*(n-i)
= (prefix[n]-prefix[i]) - Ai*(n-i)
*/