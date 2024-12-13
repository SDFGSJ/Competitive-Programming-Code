#include<bits/stdc++.h>
using namespace std;
int h,w;
char grid[25][25];
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
int dist[25][25];
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
void init(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dist[i][j]=-1;
        }
    }
}
int bfs(int r,int c){
    init();
    queue<pair<int,int>> q;
    q.emplace(r,c);
    dist[r][c]=0;
    while(!q.empty()){
        auto [nowr,nowc]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nextr=nowr+dx[i], nextc=nowc+dy[i];
            if(ingrid(nextr,nextc) && grid[nextr][nextc]=='.' && dist[nextr][nextc]==-1){
                dist[nextr][nextc]=dist[nowr][nowc]+1;
                q.emplace(nextr,nextc);
            }
        }
    }

    int res=-1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            res=max(res,dist[i][j]);
        }
    }
    return res;
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }

    int ans=-1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='.'){
                ans=max(ans,bfs(i,j));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
bfs
enumerate all possible starting point (i,j) and perform bfs from it
*/