#include<bits/stdc++.h>
using namespace std;
int grid[1505][1505];
int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=0;i<n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        grid[a][b]++,grid[c+1][b]--;
        grid[a][d+1]--,grid[c+1][d+1]++;
    }

    for(int i=0;i<=h;i++){
        for(int j=1;j<=w;j++){
            grid[i][j]+=grid[i][j-1];
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=0;j<=w;j++){
            grid[i][j]+=grid[i-1][j];
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}