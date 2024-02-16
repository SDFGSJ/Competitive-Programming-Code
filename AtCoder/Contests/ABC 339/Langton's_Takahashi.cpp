#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
int dx[4]={-1,0,1,0};   //URDL
int dy[4]={0,1,0,-1};
int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            grid[i][j]='.';
        }
    }

    int x=0,y=0,idx=0;
    for(int i=0;i<n;i++){
        if(grid[x][y]=='.'){    //white
            grid[x][y]='#';
            idx=(idx+1)%4;
        }else{  //black
            grid[x][y]='.';
            idx=((idx-1)+4)%4;
        }
        x=(x+dx[idx]+h)%h;
        y=(y+dy[idx]+w)%w;
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}