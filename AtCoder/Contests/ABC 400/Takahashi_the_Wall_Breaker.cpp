#include<bits/stdc++.h>
using namespace std;
char grid[1010][1010];
int dist[1010][1010];   //dist[i][j] = min # of front kicks to reach (i,j)
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int h,w;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
void bfs(int sr,int sc){
    deque<pair<int,int>> dq;
    dq.emplace_back(sr,sc);
    dist[sr][sc]=0;
    while(!dq.empty()){
        auto [r,c]=dq.front();dq.pop_front();
        for(int step=1;step<=2;step++){ //can kick at most 2 steps away
            for(int i=0;i<4;i++){
                int nr=r+step*dx[i],nc=c+step*dy[i];
                if(ingrid(nr,nc) && dist[nr][nc]==INT_MAX){
                    if(grid[nr][nc]=='.'){
                        if(step==1){
                            dq.emplace_front(nr,nc);
                            dist[nr][nc]=dist[r][c];
                        }   //can't determine dist[nr][nc] if step==2
                    }else{
                        dq.emplace_back(nr,nc);
                        dist[nr][nc]=dist[r][c]+1;
                    }
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dist[i][j]=INT_MAX;
        }
    }
    bfs(a,b);
    printf("%d\n",dist[c][d]);
    return 0;
}
/*
01bfs
if we walk along the road, the cost is 0
if we perform a front kick, the cost is 1
Editorial video watched
*/