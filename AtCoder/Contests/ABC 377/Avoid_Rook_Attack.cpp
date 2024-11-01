#include<bits/stdc++.h>
using namespace std;
char grid[10][10];
bool row[10],col[10];
bool ok(int r,int c){
    bool hasrook=false;
    for(int i=0;i<8;i++){
        if(i!=c && grid[r][i]=='#'){
            return false;
        }
        if(i!=r && grid[i][c]=='#'){
            return false;
        }
    }
    return true;
}
int main(){
    for(int i=0;i<8;i++){
        scanf("%s",grid[i]);
    }

    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(grid[i][j]=='.' && ok(i,j)){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}