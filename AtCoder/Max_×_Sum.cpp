#include<bits/stdc++.h>
using namespace std;
pair<int,int> v[200010];
long long sufb[200010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        multiset<int> window;
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&v[i].first);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&v[i].second);
        }

        sort(v,v+n,greater<pair<int,int>>());
        long long sufsum=0;
        for(int i=n-1;i>=0;i--){
            if(window.size()<k){
                sufsum+=v[i].second;
                window.emplace(v[i].second);
            }else if(*window.rbegin()>v[i].second){
                auto it=window.rbegin();
                sufsum-=*it;
                window.erase(window.find(*it));
                sufsum+=v[i].second;
                window.emplace(v[i].second);
            }
            sufb[i]=sufsum;
        }

        long long ans=LONG_LONG_MAX;
        for(int i=0;i<=n-k;i++){
            ans=min(ans,1ll*v[i].first*sufb[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
sort ai in desc, enumerate possible max Ai,
cal suffix sum of bi, use multiset to construct from the back
suf[i] = sum of k smallest num from i~n
*/