#include<bits/stdc++.h>
using namespace std;
char T[100010];
int dp[100010][3];  //RSP=0/1/2
char myhand[100010];    //myhand[i] = 'r' if we play rock on the ith round
int main(){
    int n,k,r,s,p;
    scanf("%d%d%d%d%d%s",&n,&k,&r,&s,&p,T+1);

    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++){
            dp[i][j]=max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        }
        if(T[i]=='r'){
            if(i<=k || myhand[i-k]!='p'){
                dp[i][2]+=p;
                myhand[i]='p';
            }
        }else if(T[i]=='p'){
            if(i<=k || myhand[i-k]!='s'){
                dp[i][1]+=s;
                myhand[i]='s';
            }
        }else{
            if(i<=k || myhand[i-k]!='r'){
                dp[i][0]+=r;
                myhand[i]='r';
            }
        }
    }
    printf("%d\n",max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}
/*
dp
dp[i][0,1,2] = max score we can get in the first i rounds, and  we play rock,scissor,paper on the ith round
*/