#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int pre[1005][1005];
int n;
void cal_prefix(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]=='.'){
                pre[i][j]=pre[i][j-1]+1;
            }else{
                pre[i][j]=pre[i][j-1];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]+=pre[i-1][j];
        }
    }
}
bool row(){
    for(int r=1;r<=n;r++){
        for(int c=1;c+5<=n;c++){
            int cnt=pre[r][c+5]-pre[r-1][c+5]-pre[r][c-1]+pre[r-1][c-1];
            if(cnt<=2){
                return true;
            }
        }
    }
    return false;
}
bool col(){
    for(int c=1;c<=n;c++){
        for(int r=1;r+5<=n;r++){
            int cnt=pre[r+5][c]-pre[r+5][c-1]-pre[r-1][c]+pre[r-1][c-1];
            if(cnt<=2){
                return true;
            }
        }
    }
    return false;
}
bool dia(){
    //top-left <-> bottom-right
    for(int r=1;r+5<=n;r++){
        for(int c=1;c+5<=n;c++){
            int cnt=0;
            for(int k=0;k<=5;k++){
                if(grid[r+k][c+k]=='.'){
                    cnt++;
                }
            }
            if(cnt<=2){
                return true;
            }
        }
    }

    //bottom-left <-> top right
    for(int r=n;r-5>=1;r--){
        for(int c=1;c+5<=n;c++){
            int cnt=0;
            for(int k=0;k<=5;k++){
                if(grid[r-k][c+k]=='.'){
                    cnt++;
                }
            }
            if(cnt<=2){
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",grid[i]+1);
    }

    cal_prefix();
    bool haveans=row()||col()||dia();
    if(haveans){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
2d prefix sum
pre[i][j] = # of '.' in the rectangle whose top-left = (1,1) and bottom-right = (i,j)

if we can find l s.t.
# of '.' in [l,l+5]<=2
or
# of '#' in [l,l+5]>=4
then the ans is yes
*/