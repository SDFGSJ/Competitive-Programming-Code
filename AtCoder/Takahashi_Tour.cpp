#include<bits/stdc++.h>
using namespace std;
set<int> Tree[200010];
void dfs(int u,int parent=-1){
    printf("%d ",u);
    for(auto v:Tree[u]){
        if(v!=parent){
            dfs(v,u);
            printf("%d ",u);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Tree[a].emplace(b);
        Tree[b].emplace(a);
    }

    dfs(1);
    printf("\n");
    return 0;
}
/*
dfs
print u when "entering node u" or "finish visiting a subtree of u"
*/