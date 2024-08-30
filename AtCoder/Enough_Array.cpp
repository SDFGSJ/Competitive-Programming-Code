#include<bits/stdc++.h>
using namespace std;
long long a[100010],pre[100010];
int main(){
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    long long ans=0;
    for(int i=1;i<=n;i++){  //enumerate left bound of continuous array
        int offset_idx=i-1;
        int cnt=(pre+n+1)-lower_bound(pre+i,pre+1+n,pre[offset_idx]+k);
        ans+=cnt;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
a[] = {0, 5, 11, 11, 3, 970}
           [i]    [idx]         [n+1]
pre[] = {0, 5, 16, 27, 30, 1000}
we want to find the first idx s.t. pre[idx]-pre[offset_idx] >= k
that is, find first idx s.t. pre[idx] >= pre[offset_idx]+k
*/