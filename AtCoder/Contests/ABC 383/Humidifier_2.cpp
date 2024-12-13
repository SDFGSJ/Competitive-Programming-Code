#include<bits/stdc++.h>
using namespace std;
char grid[15][15];
int h,w,d;
int bfs(int r1,int c1,int r2,int c2){
    set<pair<int,int>> s;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]!='#' && abs(r1-i)+abs(c1-j)<=d){
                s.emplace(i,j);
            }
            if(grid[i][j]!='#' && abs(r2-i)+abs(c2-j)<=d){
                s.emplace(i,j);
            }
        }
    }
    return (int)s.size();
}
int main(){
    scanf("%d%d%d",&h,&w,&d);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }

    int ans=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            for(int k=1;k<=h;k++){
                for(int l=1;l<=w;l++){
                    if((i!=k || j!=l) && grid[i][j]!='#' && grid[k][l]!='#'){
                        ans=max(ans,bfs(i,j,k,l));
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}