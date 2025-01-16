#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long pre[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=pre[i-1]+a[i];
    }

    long long sum=0;
    for(int i=1;i<=m;i++){
        sum+=1ll*i*a[i];
    }

    long long ans=sum;
    for(int r=m+1;r<=n;r++){
        sum=sum-(pre[r-1]-pre[r-m-1])+1ll*m*a[r];
        ans=max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
prefix sum + sliding window
cal the weighted sum of the first m terms [1,m]
for the window that ends at index m+1 to n, the weighted sum wouldd be
(current weighted sum) - (sum[r-m, r-1]) + a[r]*m
*/