#include<bits/stdc++.h>
using namespace std;
int tool[105];
int main(){
    int t,a,b,n,i;
    long long ans=0;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d%d%d",&a,&b,&n);
        for(i=0;i<n;i++){
            scanf("%d",&tool[i]);
        }

        ans+=(b-1);
        for(i=0;i<n;i++){
            long long now=min(a,1+tool[i]);
            ans+=(now-1);
        }
        ans++;
        printf("%lld\n",ans);
    }
    return 0;
}