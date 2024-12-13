#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
queue<pair<int,int>> q; //<row,col>
int dist[105][105],dx[2]={0,1},dy[2]={1,0};
int h,w;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dist[i][j]=-1;
        }
    }

    q.emplace(1,1);
    dist[1][1]=1;
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        for(int i=0;i<2;i++){
            int nextr=r+dx[i],nextc=c+dy[i];
            if(ingrid(nextr,nextc) && grid[nextr][nextc]!='#' && dist[nextr][nextc]==-1){
                dist[nextr][nextc]=dist[r][c]+1;
                q.emplace(nextr,nextc);
            }
        }
    }

    int ans=-1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            ans=max(ans,dist[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
bfs with only 2 directions
can also be solved by DP
*/