#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
char t[10005];
int h,w,x,y;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
int main(){
    scanf("%d%d%d%d",&h,&w,&x,&y);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }
    scanf("%s",t);

    vis[x][y]=true;
    for(int i=0;t[i]!='\0';i++){
        if(t[i]=='U'){
            if(ingrid(x-1,y) && grid[x-1][y]!='#'){
                x-=1;
            }
        }else if(t[i]=='R'){
            if(ingrid(x,y+1) && grid[x][y+1]!='#'){
                y+=1;
            }
        }else if(t[i]=='D'){
            if(ingrid(x+1,y) && grid[x+1][y]!='#'){
                x+=1;
            }
        }else{
            if(ingrid(x,y-1) && grid[x][y-1]!='#'){
                y-=1;
            }
        }
        vis[x][y]=true;
    }

    int ans=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='@' && vis[i][j]){
                ans++;
            }
        }
    }
    printf("%d %d %d\n",x,y,ans);
    return 0;
}