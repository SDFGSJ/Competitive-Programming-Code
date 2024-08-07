#include<bits/stdc++.h>
using namespace std;
char grid[1010][1010];
int dist[1010][1010][4];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int h,w;
bool ingrid(int r,int c){
    return 0<=r && r<h && 0<=c && c<w;
}
int zero_one_bfs(int rs,int cs,int rt,int ct){
    deque<tuple<int,int,int>> q;    //<row,col,dir>
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int k=0;k<4;k++){
                dist[i][j][k]=1e9;
            }
        }
    }

    for(int i=0;i<4;i++){
        dist[rs][cs][i]=0;
        q.push_back({rs,cs,i});
    }
    while(!q.empty()){
        auto [nowr,nowc,dir]=q.front();q.pop_front();

        for(int i=0;i<4;i++){
            int nextr=nowr+dx[i];
            int nextc=nowc+dy[i];
            if(ingrid(nextr,nextc) && grid[nextr][nextc]=='.'){
                int cost=(i==dir?0:1);  //if same dir, then no cost
                if(dist[nextr][nextc][i] > dist[nowr][nowc][dir] + cost){
                    dist[nextr][nextc][i] = dist[nowr][nowc][dir] + cost;   //update
                    if(cost==0){
                        q.push_front({nextr,nextc,i});
                    }else{
                        q.push_back({nextr,nextc,i});
                    }
                }
            }
        }
    }

    //find the dir with min turns
    int result=1e9;
    for(int i=0;i<4;i++){
        result=min(result, dist[rt][ct][i]);
    }
    return result;
}
int main(){
    int rs,cs,rt,ct;
    scanf("%d%d%d%d%d%d",&h,&w,&rs,&cs,&rt,&ct);
    rs--,cs--,rt--,ct--;
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
    }
    printf("%d\n",zero_one_bfs(rs,cs,rt,ct));
    return 0;
}
//https://www.geeksforgeeks.org/minimize-the-number-of-turns-needed-to-reach-from-top-left-cell-to-bottom-right-cell-of-the-matrix/
/*
dist[i][j][k] = min turns on grid[i][j] when dir = k
*/