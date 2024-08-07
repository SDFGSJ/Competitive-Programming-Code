#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[200010];    //<shoulder,head>
int main(){
    int n;
    scanf("%d",&n);
    long long suma=0,sumb=0;
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i].first,&a[i].second);
        suma+=a[i].first;
        sumb+=a[i].second;
    }
    long long ans=-1;
    for(int i=0;i<n;i++){
        long long result=suma-a[i].first+a[i].second;
        ans=max(ans,result);
    }
    printf("%lld\n",ans);
    return 0;
}