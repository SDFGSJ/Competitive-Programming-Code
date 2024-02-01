#include<bits/stdc++.h>
using namespace std;
char grid[55][55];
set<pair<int,int>> visited;
queue<tuple<int,int,int>> q;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    int r,c,sr,sc,gr,gc;
    scanf("%d%d%d%d%d%d",&r,&c,&sr,&sc,&gr,&gc);
    sr--,sc--,gr--,gc--;
    for(int i=0;i<r;i++){
        scanf("%s",grid[i]);
    }

    int time=0;
    q.emplace(sr,sc,time);
    visited.emplace(sr,sc);
    while(!q.empty()){
        int nowr,nowc,dist;
        tie(nowr,nowc,dist)=q.front();q.pop();

        if(nowr==gr && nowc==gc){
            printf("%d\n",dist);
            return 0;
        }

        for(int i=0;i<4;i++){
            int newr=nowr+dx[i];
            int newc=nowc+dy[i];
            if(0<newr && newr<r && 0<newc && newc<c
                && grid[newr][newc]!='#'
                && !visited.count({newr,newc})){
                    visited.emplace(newr,newc);
                    q.emplace(newr,newc,dist+1);
            }
        }
    }
    return 0;
}