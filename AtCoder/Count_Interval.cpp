#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long pre[200010];
unordered_map<long long,int> um;    //<val,cnt>
int main(){
    int n;
    long long k,ans=0;
    scanf("%d%lld",&n,&k);
    um[0]=1;    //pre[0]=0
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=pre[i-1]+a[i];
        ans+=um[pre[i]-k];
        um[pre[i]]++;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
prefix sum
when calculating pre[r], find the # of pre[l-1] whose value is pre[r]-k
since pre[r]-pre[l-1]=k <=> pre[l-1]=pre[r]-k
use unordered map<ll value,int cnt> to maintain the # of a specific prefix sum
*/