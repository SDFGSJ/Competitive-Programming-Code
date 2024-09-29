#include<bits/stdc++.h>
using namespace std;
int a[200010],window[1000010];
long long pre[400010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    pre[1]=0;
    for(int i=2;i<=n+1;i++){
        pre[i]=pre[i-1]+a[i-1];
    }
    for(int i=n+2;i<=2*n-1;i++){
        pre[i]=pre[i-1]+a[i-n-1];
    }

    for(int i=2;i<=n;i++){  //sliding window
        window[pre[i]%m]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=window[pre[i]%m];  //find #elements in [i+1, i+n-1] s.t. it has same modulo with pre[i]
        window[pre[i+1]%m]--;   //window shift
        window[pre[i+n]%m]++;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
pre[i] = cost from 1 to i
the cost from i to j = pre[j]-pre[i]
pre[j]-pre[i] = kM => pre[j]=pre[i]+kM => pre[j]=pre[i] mod M
so the problem remains to find #j's in (i,i+n-1] s.t. pre[i]=pre[j] mod M
*/