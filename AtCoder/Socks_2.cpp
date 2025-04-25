#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool matched[200010];
int calc(int k){
    int res=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;   //<diff,idx>
    for(int i=0;i+1<k;i++){
        pq.emplace(a[i+1]-a[i],i);
    }
    while(!pq.empty()){
        auto [diff,idx]=pq.top();pq.pop();
        if(matched[idx] || matched[idx+1]){
            continue;
        }
        res+=diff;
        matched[idx]=matched[idx+1]=true;
    }
    return res;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d",&a[i]);
    }

    int ans=0;
    if(k%2){    //odd
        ans=calc(k);
    }else{
        for(int i=0;i+1<k;i+=2){
            ans+=a[i+1]-a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
20 7
1 2 5 8 9 12 20
ans=7
*/