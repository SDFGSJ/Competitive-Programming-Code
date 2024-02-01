#include<bits/stdc++.h>
using namespace std;
int a[100010],grid[105][105];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    int x=0,y=0,idx=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            grid[x][y]=i;
            x+=dx[idx];
            y+=dy[idx];

            if(x<0 || y<0 || x>=h || y>=w || grid[x][y]!=0){
                x-=dx[idx];
                y-=dy[idx];
                idx=(idx+1)%4;

                x+=dx[idx];
                y+=dy[idx];
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}