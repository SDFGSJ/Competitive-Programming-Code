#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]%=m;
        printf("%d ",a[i]);
    }
    printf("\n");

    long long ans=0;
    for(long long i=0;i<n;i++){
        long long remain=1ll*n*(n+1)/2 - i*(i+1)/2 - 1ll*(n-1-i)*(n-i)/2;
        printf("remain=%lld\n",remain);
        ans+=(remain*a[i])%m;
    }
    printf("%lld\n",ans);
    return 0;
}