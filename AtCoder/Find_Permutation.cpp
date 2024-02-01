#include<bits/stdc++.h>
using namespace std;
set<int> G[200010]; //duplicate edges
int indeg[200010],prede[200010],ans[200010];    //in-deg, predecessor, answer
vector<int> dp,q;   //q:topological order
int solve(int n){
    dp.resize(n+1,0);
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.emplace_back(i);
        }
    }

    for(int i=0;i<q.size();i++){
        int u=q[i];
        for(auto v:G[u]){
            if(dp[v] < dp[u]+1){
                prede[v]=u;
                dp[v]=dp[u]+1;
            }
            if(--indeg[v]==0){
                q.emplace_back(v);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(!G[x].count(y)){
            G[x].emplace(y);
            indeg[y]++;
        }
    }

    if(solve(n)==n-1){  //max path length == n-1 <=> have ans
        printf("Yes\n");

        int idx=q[q.size()-1];  //last node of topo order, start of backtracking
        for(int num=n;num>=1;num--){
            ans[idx]=num;
            idx=prede[idx];
        }
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }else{
        printf("No\n");
    }
    return 0;
}