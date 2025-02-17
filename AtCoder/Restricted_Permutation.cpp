#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
int indeg[200010];
vector<int> topo;
bool topo_sort(int n){
    topo.clear();
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.emplace(i);
        }
    }

    while(!q.empty()){
        int now=q.top();q.pop();
        topo.emplace_back(now);
        for(auto next:G[now]){
            indeg[next]--;
            if(indeg[next]==0){
                q.emplace(next);
            }
        }
    }
    return topo.size()==n;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        indeg[b]++;
    }

    bool res=topo_sort(n);
    if(!res){
        printf("-1\n");
        return 0;
    }

    for(auto num:topo){
        printf("%d ",num);
    }
    printf("\n");
    return 0;
}
/*
topo sort + pq
for those numbers that dont have any "smaller" relationship, their in-deg is 0
since we want to find the lexicographically smallest sequence, we use priority queue when doing topo sort
*/