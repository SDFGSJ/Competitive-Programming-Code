#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        int cnt=(a+n)-lower_bound(a,a+n,2*a[i]);
        ans+=cnt;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
lower bound
for each a[i], find the # of j s.t. 2*a[i] <= a[j]
*/