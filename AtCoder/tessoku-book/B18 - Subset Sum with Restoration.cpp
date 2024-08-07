#include<bits/stdc++.h>
using namespace std;
int a[65];
bool dp[65][10010];
int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j] |= dp[i-1][j];
            if(j-a[i]>=0){
                dp[i][j] |= dp[i-1][j-a[i]];
            }
        }
    }

    if(!dp[n][s]){
        printf("-1\n");
    }else{
        vector<int> ans;
        int bag=n,sum=s;
        while(bag!=0 && sum!=0){
            if(dp[bag-1][sum-a[bag]]){
                ans.emplace_back(bag);
                sum-=a[bag];
            }
            bag-=1;
        }

        printf("%ld\n",ans.size());
        reverse(ans.begin(),ans.end());
        for(auto num:ans){
            printf("%d ",num);
        }
        printf("\n");
    }
    return 0;
}