#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
long long prea[200010],preb[200010];
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i=1;i<=n;i++){
        prea[i]=prea[i-1]+a[i];
        preb[i]=preb[i-1]+b[i];
    }

    long long ans=LONG_LONG_MAX;
    for(int i=1;i<=n && x>=i;i++){
        ans=min(ans,prea[i]+preb[i]+1ll*(x-i)*b[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
clear stage i and spend all remaining X-i times on playing stage i
notice that X-i>=0, we cant play a stage negative times
(a1+b1)+(x-1)b1
(a1+b1)+(a2+b2)+(x-2)b2
...
*/