#include<bits/stdc++.h>
using namespace std;
int cost[15][15];
int grid[205][205];
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf("%d",&grid[i][j]);
        }
    }

    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }

    int ans=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]!=-1){
                ans+=cost[grid[i][j]][1];
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
floyd warshall
*/