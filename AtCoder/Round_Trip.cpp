#include<bits/stdc++.h>
using namespace std;
int H,W;
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
bool ingrid(int r,int c){
    return 0<=r && r<H && 0<=c && c<W;
}
bool vis[1000010];
bool bfs(
    int startr,int startc,
    int goalr,int goalc,
    vector<string>& grid
){
    for(int i=0;i<H*W;i++){
        vis[i]=false;
    }
    queue<pair<int,int>> q;
    q.emplace(startr,startc);
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        if(r==goalr && c==goalc){
            return true;
        }
        if(vis[r*W+c]){
            continue;
        }
        vis[r*W+c]=true;
        for(int i=0;i<4;i++){
            int nextr=r+dx[i],nextc=c+dy[i];
            if(ingrid(nextr,nextc) && grid[nextr][nextc]=='.'){
                q.emplace(nextr,nextc);
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&H,&W);
    int sr,sc;
    vector<string> grid(H);
    for(int i=0;i<H;i++){
        cin>>grid[i];
        for(int j=0;j<W;j++){
            if(grid[i][j]=='S'){
                sr=i,sc=j;
            }
        }
    }

    vector<pair<int,int>> adj_point;    //points (r,c) that are adj to S, at most 4
    for(int i=0;i<4;i++){
        int nr=sr+dx[i], nc=sc+dy[i];
        if(ingrid(nr,nc)){
            adj_point.emplace_back(nr,nc);
        }
    }

    //enumerate all C(4,2)=6 combinations, if there exists 1 pair of points that can reach each other, the ans is yes
    bool ok=false;
    for(int i=0;i<adj_point.size();i++){
        for(int j=i+1;j<adj_point.size();j++){
            auto [r1,c1]=adj_point[i];
            auto [r2,c2]=adj_point[j];
            if(grid[r1][c1]=='#' || grid[r2][c2]=='#'){ //only do bfs when both points are road
                continue;
            }
            ok|=bfs(r1,c1,r2,c2,grid);
        }
    }

    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
bfs
there exists a cycle containing S
<=> there exists at least 1 node s.t. there are 2 paths from S to that node
to check whether there exists a cycle that starts from S and ends at S,
we can use bfs to check whether the points adj to S can reach each other
solved after reading editorial
*/