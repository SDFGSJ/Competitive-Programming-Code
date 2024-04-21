#include<bits/stdc++.h>
using namespace std;
int a[200010];
set<int> visited;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    long long ans=1ll*k*(k+1)/2;
    for(int i=0;i<n;i++){
        if(1<=a[i] && a[i]<=k && visited.find(a[i])==visited.end()){
            visited.emplace(a[i]);
            ans-=a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}