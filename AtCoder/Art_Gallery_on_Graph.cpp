#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
priority_queue<pair<int,int>> pq;   //<stamina,vertex idx>
int stamina[200010];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for(int i=1;i<=n;i++){
        stamina[i]=-1;
    }

    for(int i=0;i<k;i++){
        int p,h;
        scanf("%d%d",&p,&h);
        //stamina[p]=h;
        pq.emplace(h,p);
    }

    while(!pq.empty()){
        auto [sta,idx]=pq.top();pq.pop();
        if(stamina[idx]!=-1){  //sta<=stamina[idx] also works
            continue;
        }
        stamina[idx]=sta;
        for(auto neigh:G[idx]){
            pq.emplace(sta-1,neigh);
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(stamina[i]>=0){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++){
        if(stamina[i]>=0){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}
/*
similar to dijkstra + priority queue
push all the guards (h,p) into pq, start expanding from the guard with the largest stamina
if we meet a vertex whose stamina <= current stamina, skip that vertex
*/