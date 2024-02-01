#include<bits/stdc++.h>
using namespace std;
int a[100010];
long long pre[100010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    long long ans=0;
    for(int i=1;i<=n-k+1;i++){
        ans+=pre[i+k-1]-pre[i-1];
    }
    printf("%lld\n",ans);
    return 0;
}