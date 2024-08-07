#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010],que;
int indeg[100010],dp[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        indeg[y]++;
    }

    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            que.emplace_back(i);
        }
    }

    for(int i=0;i<que.size();i++){
        int now=que[i];
        for(auto next:G[now]){
            dp[next]=max(dp[next], dp[now]+1);
            indeg[next]--;
            if(indeg[next]==0){
                que.emplace_back(next);
            }
        }
    }
    printf("%d\n",*max_element(dp+1, dp+1+n));
    return 0;
}