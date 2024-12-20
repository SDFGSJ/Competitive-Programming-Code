#include<bits/stdc++.h>
using namespace std;
char grid[55][55];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int h,w;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
int dist[55][55];
queue<pair<int,int>> q;
int main(){
    int black=0;
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='#'){
                black++;
            }
        }
    }

    bool haveans=false;
    q.emplace(1,1);
    dist[1][1]=1;
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        if(r==h && c==w){
            haveans=true;
            break;
        }
        for(int i=0;i<4;i++){
            int nr=r+dx[i], nc=c+dy[i];
            if(ingrid(nr,nc) && grid[nr][nc]=='.' && !dist[nr][nc]){
                q.emplace(nr,nc);
                dist[nr][nc]=dist[r][c]+1;
            }
        }
    }

    if(haveans){
        printf("%d\n",h*w-black-dist[h][w]);
    }else{
        printf("-1\n");
    }
    return 0;
}
/*
bfs
ans = HW - (# of black square) - shortest path from (1,1) to (H,W)
*/