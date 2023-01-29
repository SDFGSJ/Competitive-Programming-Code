#include<bits/stdc++.h>
using namespace std;
vector<int> coins;
int dp[1000010];
/*
dp[i]=number of ways to make sum=i
*/
int main(){
    int n,sum,i;
    scanf("%d%d",&n,&sum);

    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        dp[num]=1;
        coins.push_back(num);
    }

    dp[0]=0;    //base case
    //for some sum i, try to use each coin
    for(i=1;i<=sum;i++){
        for(auto j:coins){
            if(i>=j){
                dp[i] += dp[i-j];
                dp[i] = dp[i] % ((int)1e9+7);
            }
        }
    }
    printf("%d\n",dp[sum]);
    return 0;
}