#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int h,w;
queue<pair<int,int>> q;    //<row,col>
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};  //URDL
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
const string str="v<^>";    //DLUR
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='E'){
                q.emplace(i,j);
            }
        }
    }

    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nr=r+dx[i],nc=c+dy[i];
            if(ingrid(nr,nc) && grid[nr][nc]=='.'){
                grid[nr][nc]=str[i];
                q.emplace(nr,nc);
            }
        }
    }

    for(int i=1;i<=h;i++){
        printf("%s\n",grid[i]+1);
    }
    return 0;
}
/*
multi source bfs
*/