#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;
long long dp[105][100010];
/*
dp[i][j]=the max value of the first i items and a bag with capacity = j
*/
int main(){
    int N,W,w,v,i,j;
    scanf("%d%d",&N,&W);
    for(i=1;i<=N;i++){
        scanf("%d%d",&w,&v);
        a.emplace_back(w,v);    //start inserting from a[0]
    }

    for(i=1;i<=N;i++){
        tie(w,v)=a[i-1];    //0-indexed
        for(j=0;j<=W;j++){  //try all capacity from 0 ~ W
            dp[i][j] = dp[i-1][j];  //dont pick item i
            if(j-w>=0){ //check index before accessing
                dp[i][j] = max(dp[i][j], dp[i-1][j-w]+v);   //pick item i
            }
        }
    }

    printf("%lld\n",dp[N][W]);
    return 0;
}