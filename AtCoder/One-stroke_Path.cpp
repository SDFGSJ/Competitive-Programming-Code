#include<bits/stdc++.h>
using namespace std;
vector<int> G[10];
int n,cnt;
void dfs(int u,int prede,int vis_mask){
    if(vis_mask == ((1<<n)-1)){
        cnt++;
        return;
    }

    for(auto v:G[u]){
        if(v!=prede && ((vis_mask & (1<<(v-1))) == 0)){
            dfs(v,u,vis_mask ^ (1<<(v-1)));
        }
    }
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    dfs(1,-1,1);
    printf("%d\n",cnt);
    return 0;
}
/*
dfs + bit mask
use bit mask instead of bool vis[]

Note. can also be solved by bitDP
*/