#include<bits/stdc++.h>
using namespace std;
vector<int> Tree[200010];
int cost[200010],ans[200010];
void dfs(int u,int parent,int counter){
    ans[u]+=counter;
    for(auto v:Tree[u]){
        if(v!=parent){
            dfs(v,u,counter+cost[v]);
        }
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Tree[a].emplace_back(b);
        Tree[b].emplace_back(a);
    }

    for(int i=0;i<q;i++){
        int p,x;
        scanf("%d%d",&p,&x);
        cost[p]+=x;
    }

    dfs(1,-1,cost[1]);

    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
cost[v] = counter added on node v
dfs
*/