#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
int ans[105];
int h,w;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
int dx[4]={1,1,-1,-1}, dy[4]={1,-1,1,-1};
int cross_size(int r,int c){
    int sz;
    bool ok=true;
    for(sz=1;;){
        for(int i=0;i<4;i++){
            int nr=r+dx[i]*sz, nc=c+dy[i]*sz;
            if(!ingrid(nr,nc) || grid[nr][nc]!='#'){
                ok=false;
            }
        }
        if(ok){
            sz++;
        }else{
            break;
        }
    }

    return sz-1;
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='#'){
                int size=cross_size(i,j);
                if(size>=1){
                    ans[size]++;
                }
            }
        }
    }

    for(int i=1;i<=min(h,w);i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
simulation
*/