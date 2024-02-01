#include<bits/stdc++.h>
using namespace std;
int a[200010];
int color[200010];    //0:white, 1:gray, 2:black
int parent[200010]; //parent[i]:i's parent
int cycle_start,cycle_end;
vector<int> G[200010],ans;
void dfs(int u){
    color[u]=1;
    for(auto v:G[u]){
        if(!color[v]){
            parent[v]=u;
            dfs(v);
        }else if(color[v]==1){
            cycle_start=v;
            cycle_end=u;
        }
    }
    color[u]=2;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        G[i].emplace_back(a[i]);
    }

    for(int i=1;i<=n;i++){
        if(!color[i]){
            dfs(i);
        }
    }

    for(int i=cycle_end;i!=cycle_start;i=parent[i]){
        ans.emplace_back(i);
    }
    ans.emplace_back(cycle_start);

    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}