#include<bits/stdc++.h>
using namespace std;
unordered_set<int> G[300010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);

    int ans=n;
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int u,v;
            scanf("%d%d",&u,&v);
            ans=ans-(G[u].size()==0)-(G[v].size()==0);
            G[u].emplace(v);
            G[v].emplace(u);
        }else{
            int v;
            scanf("%d",&v);
            if(G[v].size()!=0){ //v might not be connected to any vertex
                for(auto node:G[v]){
                    G[node].erase(v);
                    ans+=(G[node].size()==0);
                }
                G[v].clear();   //use clear instead of for loop+erase to prevent RE
                ans+=(G[v].size()==0);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
maintain an adj list and use degree to solve
*/