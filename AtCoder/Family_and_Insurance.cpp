#include<bits/stdc++.h>
using namespace std;
vector<int> Tree[300010];
int insu_depth[300010];
int ans;
void dfs(int u,int max_depth,int cur_lv){
    if(insu_depth[u]>0 || cur_lv<=max_depth){
        ans++;
    }

    for(auto v:Tree[u]){
        dfs(v,max(max_depth, cur_lv+insu_depth[u]), cur_lv+1);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++){
        int p;
        scanf("%d",&p);
        Tree[p].emplace_back(i);
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        insu_depth[x]=max(insu_depth[x],y);
    }

    dfs(1,0,1);
    printf("%d\n",ans);
    return 0;
}
/*
dfs
maintain each person's insurance depth(take max of it if duplicate)
view this problem as a directed tree
during recursion, max_depth is the max reachable depth from ancestor
while cur_lv+insu_depth[u] is the max reachable depth from current node u
*/