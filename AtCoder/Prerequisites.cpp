#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010],rG[200010];
int indeg[200010];
bool vis[200010];
queue<int> q;
vector<int> ans;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int c;
        scanf("%d",&c);
        for(int j=0;j<c;j++){
            int p;
            scanf("%d",&p);
            G[p].emplace_back(i);
            rG[i].emplace_back(p);
            indeg[i]++;
        }
    }

    //find the books that must be read before reading book 1 by doing BFS on reversed graph
    q.emplace(1);
    while(!q.empty()){
        int now=q.front();q.pop();
        if(vis[now]){
            continue;
        }
        vis[now]=true;
        for(auto next:rG[now]){
            q.emplace(next);
        }
    }

    //find the books related to book 1 whose in-deg = 0 as starting point
    for(int i=1;i<=n;i++){
        if(vis[i] && !indeg[i]){
            ans.emplace_back(i);
        }
    }

    //topo sort
    for(int i=0;i<ans.size();i++){
        for(auto v:G[ans[i]]){
            indeg[v]--;
            if(vis[v] && !indeg[v]){    //only read books related to book 1 by checking vis[v]
                ans.emplace_back(v);
            }
        }
    }

    for(int i=0;i<ans.size()-1;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
reversed graph + bfs + topo sort
vis[i] = true if book i must be read before reading book 1
first, do bfs on reversed graph starting from node 1 to find the minimum set of books to read book 1
then do topo sort on those selected books
*/