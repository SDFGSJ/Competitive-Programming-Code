#include<bits/stdc++.h>
using namespace std;
char s[2010],t[2010];
int dp[2010][2010];
int main(){
    scanf("%s%s",s,t);
    int m=strlen(s),n=strlen(t);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}