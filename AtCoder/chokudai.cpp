#include<bits/stdc++.h>
using namespace std;
char str[100010];
int dp[10];
const int mod=1e9+7;
int main(){
    scanf("%s",str);
    int len=strlen(str);

    dp[0]=1;
    for(int i=0;i<len;i++){
        for(int j=1;j<=8;j++){
            if(str[i]==".chokudai"[j]){
                dp[j]+=dp[j-1];
                dp[j]%=mod;
            }
        }
    }
    printf("%d\n",dp[8]);
    return 0;
}
/*
dp[i] = #ways to construct ".chokudai"[1~i] from str[1~now]
*/