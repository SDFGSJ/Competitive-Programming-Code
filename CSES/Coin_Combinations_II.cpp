#include<bits/stdc++.h>
using namespace std;
vector<int> coins;
int dp[1000010];
/*
dp[i]=number of ways to make sum=i
*/
int main(){
    int n,sum,i,j;
    scanf("%d%d",&n,&sum);

    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        coins.push_back(num);
    }

    dp[0]=1;    //base case
    /*Since we now loop over the coins before the sum,
    we only go through the set of coins once,
    so it's impossible to create two combinations with the same set of coins ordered differently.*/
    for(auto i:coins){
        for(j=i;j<=sum;j++){
            dp[j] += dp[j-i];
            dp[j] = dp[j] % ((int)1e9+7);
        }
    }
    printf("%d\n",dp[sum]);
    return 0;
}