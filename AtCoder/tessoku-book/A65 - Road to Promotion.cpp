#include<bits/stdc++.h>
using namespace std;
vector<int> Tree[100010];
int sz[100010];
int dfs(int u,int parent=-1){
    sz[u]=1;
    for(auto child:Tree[u]){
        if(child!=parent){
            sz[u]+=dfs(child,u);
        }
    }
    return sz[u];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int a;
        scanf("%d",&a);
        Tree[a].emplace_back(i);
        Tree[i].emplace_back(a);
    }

    dfs(1);

    for(int i=1;i<=n;i++){
        printf("%d ",sz[i]-1);
    }
    printf("\n");
    return 0;
}