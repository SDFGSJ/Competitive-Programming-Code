#include<bits/stdc++.h>
using namespace std;
char grid[2005][2005];
pair<int,int> S,G;
queue<pair<int,int>> q;
int dist[2005][2005];
int h,w,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};  //URDL
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
void mark_obstacle(int r,int c,int dir){    //start from (nextr,nextc), mark '.' or '!' as '!' along direction dir
    int nextr=r+dx[dir], nextc=c+dy[dir];
    while(ingrid(nextr,nextc) && (grid[nextr][nextc]=='.' || grid[nextr][nextc]=='!')){
        grid[nextr][nextc]='!';
        nextr+=dx[dir];
        nextc+=dy[dir];
    }
}
void add_sight_line(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='^'){
                mark_obstacle(i,j,0);
            }else if(grid[i][j]=='>'){
                mark_obstacle(i,j,1);
            }else if(grid[i][j]=='v'){
                mark_obstacle(i,j,2);
            }else if(grid[i][j]=='<'){
                mark_obstacle(i,j,3);
            }
        }
    }
}
bool is_obstacle(int i,int j){
    return grid[i][j]=='^' || grid[i][j]=='>' || grid[i][j]=='v' || grid[i][j]=='<'
     || grid[i][j]=='!' || grid[i][j]=='#';
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){  //1-indexed
        scanf("%s",grid[i]+1);
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='S'){
                S={i,j};
            }else if(grid[i][j]=='G'){
                G={i,j};
            }
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dist[i][j]=INT_MAX;
        }
    }

    add_sight_line();

    q.push(S);
    dist[S.first][S.second]=0;
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();

        if(G.first==r && G.second==c){
            printf("%d\n",dist[r][c]);
            return 0;
        }

        for(int i=0;i<4;i++){
            int nextr=r+dx[i], nextc=c+dy[i];
            if(ingrid(nextr,nextc) && !is_obstacle(nextr,nextc) && dist[nextr][nextc]==INT_MAX){
                q.emplace(nextr,nextc);
                dist[nextr][nextc]=dist[r][c]+1;
            }
        }
    }
    printf("-1\n");
    return 0;
}
/*
mark eyesight as obstacle and do bfs
*/