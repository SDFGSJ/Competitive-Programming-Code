#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int h,w;
int dist[1005][1005];   //dist[i][j] = min # of warps to reach (i,j)
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
deque<pair<int,int>> dq;   //<r,c>
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
void walk(int r,int c){
    for(int i=0;i<4;i++){
        int nr=r+dx[i],nc=c+dy[i];
        if(ingrid(nr,nc) && grid[nr][nc]=='.' && dist[r][c]<dist[nr][nc]){
            dq.emplace_front(nr,nc);
            dist[nr][nc]=dist[r][c];
        }
    }
}
void warp(int r,int c){
    for(int dr=-2;dr<=2;dr++){
        for(int dc=-2;dc<=2;dc++){
            int nr=r+dr,nc=c+dc;
            if(ingrid(nr,nc) && grid[nr][nc]=='.' && dist[r][c]+1<dist[nr][nc]){
                dq.emplace_back(nr,nc);
                dist[nr][nc]=dist[r][c]+1;
            }
        }
    }
}
int main(){
    int sr,sc,gr,gc;
    scanf("%d%d%d%d%d%d",&h,&w,&sr,&sc,&gr,&gc);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dist[i][j]=INT_MAX;
        }
    }

    dq.emplace_back(sr,sc);
    dist[sr][sc]=0;
    while(!dq.empty()){
        auto [r,c]=dq.front();dq.pop_front();
        walk(r,c);
        warp(r,c);
    }

    int ans=dist[gr][gc];
    if(ans==INT_MAX){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
01bfs
*/