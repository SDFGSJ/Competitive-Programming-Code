#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool dp[105][10500];
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }

    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(dp[i-1][j]){
                dp[i][j+a[i]]=dp[i][j+b[i]]=true;
            }
        }
    }
    if(dp[n][x]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
dp
dp[i][j] = true if takahashi can be at the coordinate j after the first i jumps
*/