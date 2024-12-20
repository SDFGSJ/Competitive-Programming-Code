#include<bits/stdc++.h>
using namespace std;
vector<int> T[200010];
int prede[200010];
void dfs(int u,int parent=-1){
    prede[u]=parent;
    for(auto v:T[u]){
        if(v!=parent){
            dfs(v,u);
        }
    }
}
stack<int> s;
int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        T[u].emplace_back(v);
        T[v].emplace_back(u);
    }

    dfs(x);

    int now=y;
    while(now!=-1){
        s.emplace(now);
        now=prede[now];
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}
/*
prede[i] = i's predecessor
take x or y as root and dfs, and backtrace using predecessor
*/