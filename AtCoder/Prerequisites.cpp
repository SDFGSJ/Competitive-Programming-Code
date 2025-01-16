#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
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
            G[i].emplace_back(p);
            indeg[p]++;
        }
    }

    q.emplace(1);
    while(!q.empty()){
        int now=q.front();q.pop();
        if(vis[now]){
            continue;
        }
        vis[now]=true;
        ans.emplace_back(now);
        for(auto next:G[now]){
            q.emplace(next);
        }
    }
    for(int i=ans.size()-1;i>=1;i--){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}