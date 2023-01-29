#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
/*
dp[i][j] = min number of cuts to turn an i*j rectangle into several squares
*/
int main(){
    int a,b,i,j,k;
    scanf("%d%d",&a,&b);

    //initialize
    for(i=0;i<=a;i++){
        for(j=0;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
            }else{
                dp[i][j]=1e9;
            }
        }
    }

    //start enumerating from 1*1 to a*b
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            for(k=1;k<=i-1;k++){    //row
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for(k=1;k<=j-1;k++){    //column
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }

    printf("%d\n",dp[a][b]);
    return 0;
}