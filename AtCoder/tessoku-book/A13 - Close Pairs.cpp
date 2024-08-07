#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        int idx=upper_bound(a,a+n,a[i]+k)-a;
        ans+=idx-i-1;
    }
    printf("%lld\n",ans);
    return 0;
}