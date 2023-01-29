#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long dp[5010][5010];
/*
dp[i][j] = the max score that the first player can get when focusing on a[i...j]
*/
long long prefix[5010];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //prefix sum
    prefix[0]=a[0];
    for(i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    
    //initialize dp array to INF
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dp[i][j]=INT_MAX;
        }
    }

    //base case
    for(i=0;i<n;i++){
        dp[i][i]=a[i];
    }
    for(int len=2;len<=n;len++){    //try all possible interval lengths(2 ~ n)
        for(i=0;i+len-1<n;i++){
            int j=i+len-1;  //right bound
            dp[i][j] = prefix[j]-prefix[i-1] - min(dp[i+1][j], dp[i][j-1]);
        }
    }

    printf("%lld\n",dp[0][n-1]);
    return 0;
}