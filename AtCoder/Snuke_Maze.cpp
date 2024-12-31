#include<bits/stdc++.h>
using namespace std;
char grid[505][505];
bool vis[505][505];
int h,w;
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
const string str="snuke";
bool hasans;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
void dfs(int r,int c,int idx){
    //(r,c) is not in grid || not the right char || (r,c) has been visited
    if(!ingrid(r,c) || str[idx]!=grid[r][c] || vis[r][c]){
        return;
    }

    vis[r][c]=true;
    if(r==h && c==w){
        hasans=true;
        return;
    }
    for(int i=0;i<4;i++){
        int nextr=r+dx[i], nextc=c+dy[i];
        dfs(nextr,nextc,(idx+1)%5);
    }
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }

    dfs(1,1,0);
    if(hasans){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
dfs

Note. we can use vis[h][w] to decide the ans, rather than declaring another bool var hasans
if vis[h][w] is true, that means we have visited (h,w) and the char on (h,w) is correct
so the ans is yes
*/