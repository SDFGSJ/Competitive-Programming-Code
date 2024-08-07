#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,b;
    scanf("%d%d%d",&n,&m,&b);
    long long suma=0,sumb=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        suma+=num;
    }
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        sumb+=num;
    }

    long long ans=suma*m+sumb*n+1ll*b*m*n;
    printf("%lld\n",ans);
    return 0;
}