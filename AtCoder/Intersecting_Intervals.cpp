#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[500010];
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);

    long long ans=0;
    for(int i=0;i<n;i++){
        auto [st,en]=a[i];
        while(!pq.empty() && pq.top()<st){
            pq.pop();
        }
        ans+=pq.size();
        pq.emplace(en);
    }
    printf("%lld\n",ans);
    return 0;
}