#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    int n,i;
    long long ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<n;i++){
        ans+=abs( min(a[i]-a[i-1], 0ll) );
        a[i]+=abs( min(a[i]-a[i-1], 0ll) );
    }
    printf("%lld\n",ans);
    return 0;
}