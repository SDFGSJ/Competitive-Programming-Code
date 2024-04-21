#include<bits/stdc++.h>
using namespace std;
int h,w,sr,sc,tr,tc;    //sr = start row idx, sc = start col idx
char grid[205][205];
int energy[205][205];
queue<tuple<int,int,int>> q;    //<medicine row idx, col idx, energy> queue to record the place of medicine
bool valid(int r,int c){
    return 0<=r && r<h && 0<=c && c<w && grid[r][c]!='#';
}
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
bool bfs(int r,int c,int e){
    queue<tuple<int,int,int>> que;  //queue to do usual bfs traversal
    set<pair<int,int>> visited;
    que.emplace(r,c,0);
    visited.emplace(r,c);
    while(!que.empty()){
        auto [nowr,nowc,nowe]=que.front();que.pop();
        if(nowr==tr && nowc==tc){
            return true;
        }

        if(energy[nowr][nowc]){ //encounter a medicine
            q.emplace(nowr,nowc,energy[nowr][nowc]);
            energy[nowr][nowc]=0;
        }

        for(int i=0;i<4;i++){
            int nextr=nowr+di[i];
            int nextc=nowc+dj[i];
            if(valid(nextr,nextc) && nowe+1<=e && visited.find({nextr,nextc})==visited.end()){
                que.emplace(nextr,nextc,nowe+1);
                visited.emplace(nextr,nextc);
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
        for(int j=0;j<w;j++){
            if(grid[i][j]=='S'){
                sr=i,sc=j;
            }else if(grid[i][j]=='T'){
                tr=i,tc=j;
            }
        }
    }

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int r,c,e;
        scanf("%d%d%d",&r,&c,&e);
        r--,c--;
        energy[r][c]=e;
    }

    q.emplace(sr,sc,energy[sr][sc]);
    energy[sr][sc]=0;   //used up this medicine
    while(!q.empty()){
        int nowr,nowc,nowe;
        tie(nowr,nowc,nowe)=q.front();q.pop();

        if(bfs(nowr,nowc,nowe)){    //do bfs starting from (nowr,nowc) where max dist = nowe
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
/*
start from S, perform bfs to search whether there's a reachable medicine nearby
if such medicine exists, push it to q
if no, then we can't reach the goal
keep trying until we reach the goal
*/