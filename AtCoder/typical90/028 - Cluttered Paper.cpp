#include<bits/stdc++.h>
using namespace std;
int grid[1010][1010],cnt[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int lx,ly,rx,ry;
        scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
        grid[lx][ly]++,grid[rx][ry]++;
        grid[lx][ry]--,grid[rx][ly]--;
    }

    for(int i=0;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            grid[i][j]+=grid[i][j-1];
        }
    }

    for(int i=1;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            grid[i][j]+=grid[i-1][j];
        }
    }

    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            if(grid[i][j]!=0){
                cnt[grid[i][j]]++;
            }
        }
    }

    for(int i=1;i<=n;i++){
        printf("%d\n",cnt[i]);
    }
    return 0;
}