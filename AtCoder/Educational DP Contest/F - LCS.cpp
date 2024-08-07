#include<bits/stdc++.h>
using namespace std;
int dp[3005][3005];
char s[3005],t[3005];
int main(){
    scanf("%s%s",s,t);
    int m=strlen(s), n=strlen(t);
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

    vector<char> str;
    int i=m,j=n;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            str.emplace_back(s[i-1]);
            i--,j--;
        }else if(dp[i-1][j] > dp[i][j-1]){  //go back to larger place
            i--;
        }else{
            j--;
        }
    }

    reverse(str.begin(),str.end());
    for(auto c:str){
        printf("%c",c);
    }
    printf("\n");
    return 0;
}