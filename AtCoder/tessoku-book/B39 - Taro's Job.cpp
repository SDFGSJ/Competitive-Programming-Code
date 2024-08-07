#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[200010];
priority_queue<long long> pq;
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a[i].first,&a[i].second);
    }
    sort(a,a+n);

    long long ans=0;
    for(int i=1,idx=0;i<=d;i++){
        while(idx<n && a[idx].first==i){
            pq.emplace(a[idx].second);
            idx++;
        }
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    printf("%lld\n",ans);
    return 0;
}