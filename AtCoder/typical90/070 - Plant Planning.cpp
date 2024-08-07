#include<bits/stdc++.h>
using namespace std;
int x[100010],y[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }

    sort(x,x+n);
    sort(y,y+n);
    int medx=x[n/2],medy=y[n/2];
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(x[i]-medx);
        ans+=abs(y[i]-medy);
    }
    printf("%lld\n",ans);
    return 0;
}