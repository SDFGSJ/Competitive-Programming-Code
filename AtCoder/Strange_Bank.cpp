#include<bits/stdc++.h>
using namespace std;
int dp[100010];
vector<int> currency;
void prepare_currency(int num,int n){
    for(int i=num;i<=n;i*=num){
        currency.emplace_back(i);
    }
}
int main(){
    int n;
    scanf("%d",&n);

    currency.emplace_back(1);
    prepare_currency(6,n);
    prepare_currency(9,n);
    for(int i=0;i<=n;i++){
        dp[i]=INT_MAX;
    }

    dp[0]=0;
    for(int i=0;i<n;i++){
        //if(dp[i]!=INT_MAX){   //since we can withdraw 1, when expanding dp[i], dp[i+1] will not be INT_MAX
            for(auto curr:currency){
                if(i+curr<=n){
                    dp[i+curr]=min(dp[i+curr],dp[i]+1);
                }
            }
        //}
    }
    printf("%d\n",dp[n]);
    return 0;
}
/*
dp[i] = min # of coins to withdraw i
6^6=46656 and 9^5=59049, so there are at most 1+6+5=12 coins for each transition
*/