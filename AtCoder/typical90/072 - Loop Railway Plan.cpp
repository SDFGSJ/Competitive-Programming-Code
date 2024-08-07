#include<bits/stdc++.h>
using namespace std;
char grid[20][20];
int color[20][20];  //0:white, 1:gray, 2:black
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int h,w,start_r,start_c,ans=-1;
bool ingrid(int r,int c){
    return 0<=r && r<h && 0<=c && c<w;
}
void dfs(int r,int c,int parent_r,int parent_c,int step){
    color[r][c]=1;
    for(int i=0;i<4;i++){
        int nextr=r+dx[i],nextc=c+dy[i];
        if(nextr==parent_r && nextc==parent_c){
            continue;
        }
        if(ingrid(nextr,nextc) && grid[nextr][nextc]!='#'){
            if(!color[nextr][nextc]){
                dfs(nextr,nextc,r,c,step+1);
            }else if(color[nextr][nextc]==1 && nextr==start_r && nextc==start_c){   //detect cycle and return back to starting point
                ans=max(ans,step);
            }
        }
    }
    color[r][c]=2;
}
void clear_grid(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            color[i][j]=0;
        }
    }
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            start_r=i,start_c=j;
            clear_grid();
            if(grid[i][j]!='#' && !color[i][j]){
                dfs(i,j,-1,-1,1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}