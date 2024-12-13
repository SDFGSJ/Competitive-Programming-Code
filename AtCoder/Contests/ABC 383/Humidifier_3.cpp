#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int dist[1005][1005];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int h,w,d;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
queue<pair<int,int>> q;
int main(){
    scanf("%d%d%d",&h,&w,&d);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
        for(int j=1;j<=w;j++){
            dist[i][j]=1e9;
            if(grid[i][j]=='H'){
                q.emplace(i,j);
                dist[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nextr=r+dx[i], nextc=c+dy[i];
            if(ingrid(nextr,nextc) && grid[nextr][nextc]=='.' && dist[nextr][nextc]==1e9){
                dist[nextr][nextc]=dist[r][c]+1;
                q.emplace(nextr,nextc);
            }
        }
    }

    int ans=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(dist[i][j]<=d){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
multiple source bfs
*/