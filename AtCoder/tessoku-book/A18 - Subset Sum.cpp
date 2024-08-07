#include<bits/stdc++.h>
using namespace std;
int a[65];
bool dp[65][10010];
int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j] |= dp[i-1][j];
            if(j-a[i]>=0){
                dp[i][j] |= dp[i-1][j-a[i]];
            }
        }
    }
    if(dp[n][s]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
dp[i][j] = true if we can choose some cards from 1-i to have sum = j
*/