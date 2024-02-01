#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
int color[200010];  //0 white, 1 gray, 2 black
int cnt;
void dfs(int u,int parent){
    color[u]=1; //get in, mark it gray
    for(auto v:G[u]){
        if(v==parent){
            continue;
        }
        if(!color[v]){  //white => visit
            dfs(v,u);
        }else if(color[v]==1){  //gray => meet a cycle
            cnt++;
        }
    }
    color[u]=2; //finish, mark it black
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for(int i=0;i<n;i++){
        if(!color[i]){
            dfs(i,0);
        }
    }
    printf("%d\n",cnt);
    return 0;
}