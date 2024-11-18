#include<bits/stdc++.h>
using namespace std;
char s[3010];
long long dp[3010][3010];
const int mod=998244353;
int main(){
    scanf("%s",s+1);    //1-indexed for easier implementation
    int len=strlen(s+1);

    dp[0][0]=1;
    for(int i=1;i<=len;i++){
        for(int j=i;j>=0;j--){  //fill the table from the back
            if(s[i]=='('){
                if(j-1>=0){ //check whether j-1 is valid
                    dp[i][j]+=dp[i-1][j-1];
                    dp[i][j]%=mod;
                }
            }else if(s[i]==')'){
                if(j+1<=i){
                    dp[i][j]+=dp[i-1][j+1];
                    dp[i][j]%=mod;
                }
            }else{
                if(j-1>=0){
                    dp[i][j]+=dp[i-1][j-1];
                    dp[i][j]%=mod;
                }
                if(j+1<=i){
                    dp[i][j]+=dp[i-1][j+1];
                    dp[i][j]%=mod;
                }
            }
        }
    }
    printf("%lld\n",dp[len][0]);
    return 0;
}
/*
dp[i][j] = from s[1-i], number of ways to have [# of '('] - [# of ')'] = j
s[i] = '(' => dp[i][j] += dp[i-1][j-1]
s[i] = ')' => dp[i][j] += dp[i-1][j+1]
s[i] = '?' => dp[i][j] += dp[i-1][j-1] + dp[i-1][j+1]
check whether j-1, j+1 is valid before accessing
the ans would be dp[length of s][0]
*/