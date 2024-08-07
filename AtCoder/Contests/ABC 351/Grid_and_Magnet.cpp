#include<bits/stdc++.h>
using namespace std;
int h,w;
char grid[1005][1005];
vector<pair<int,int>> magnet;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool visited[1005][1005];

bool ingrid(int i,int j){
    return 0<=i && i<h && 0<=j && j<w;
}
bool magnet_nearby(int r,int c){
    for(int i=0;i<4;i++){
        int newr=r+dx[i];
        int newc=c+dy[i];
        if(ingrid(newr,newc) && grid[newr][newc]=='#'){
            return true;
        }
    }
    return false;
}
int bfs(int i,int j){
    int result=0;   //#grids that are not next to a magnet
    queue<pair<int,int>> q;
    set<pair<int,int>> ones;    //#grids that are next to a magnet
    q.emplace(i,j);
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();

        if(visited[r][c]){
            continue;
        }
        if(!magnet_nearby(r,c)){
            visited[r][c]=true;
            result++;
        }else{  //dont mark as true
            ones.emplace(r,c);
        }

        if(!magnet_nearby(r,c)){    //expand only when no magnet nearby
            for(int i=0;i<4;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];
                if(ingrid(newr,newc) && grid[newr][newc]!='#'){
                    q.emplace(newr,newc);
                }
            }
        }
    }
    return result+ones.size();
}

int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
        for(int j=0;j<w;j++){
            if(grid[i][j]=='#'){
                visited[i][j]=true;
            }
        }
    }

    int ans=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!visited[i][j]){
                ans=max(ans,bfs(i,j));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}