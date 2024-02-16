#include<bits/stdc++.h>
using namespace std;
int grid[15][15];
int h,w,ans;
int dx[2]={0,1};
int dy[2]={1,0};
bool visited[15][15];
bool ingrid(int r,int c){
    return 0<=r && r<h && 0<=c && c<w;
}
void dfs(int r,int c,set<int> s){
    if(visited[r][c]){
        return;
    }
    visited[r][c]=true;
    s.emplace(grid[r][c]);

    if(r==h-1 && c==w-1 && s.size()==h+w-1){
        ans++;
    }

    for(int i=0;i<2;i++){
        if(ingrid(r+dx[i],c+dy[i])){
            dfs(r+dx[i], c+dy[i], s);
        }
    }
    visited[r][c]=false;
    s.erase(s.find(grid[r][c]));
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&grid[i][j]);
        }
    }

    set<int> s;
    dfs(0,0,s);
    printf("%d\n",ans);
    return 0;
}