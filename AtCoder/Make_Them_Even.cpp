#include<bits/stdc++.h>
using namespace std;
int grid[505][505];
vector<tuple<int,int,int,int>> ans;
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&grid[i][j]);
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]%2){
                if(j+1<w){
                    grid[i][j+1]++;
                    grid[i][j]--;
                    ans.emplace_back(i,j,i,j+1);
                }else if(i+1<h){
                    grid[i+1][j]++;
                    grid[i][j]--;
                    ans.emplace_back(i,j,i+1,j);
                }
            }
        }
    }

    printf("%ld\n",ans.size());
    for(auto tu:ans){
        int a,b,c,d;
        tie(a,b,c,d)=tu;
        printf("%d %d %d %d\n",a+1,b+1,c+1,d+1);
    }
    return 0;
}
/*
greedy simulation
for each grid, if it has even coins, skip it
if it has odd coins, move 1 coin to the right, if there's no right, move it down
never move up or left since those grids already have even # of coins
only move the coins to the right or down(if right is not available)
start from top-left corner, from l to r, from top to bottom
*/