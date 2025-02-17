#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
bool dp[200010][2];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }

    dp[1][0]=dp[1][1]=true;
    for(int i=2;i<=n;i++){
        if(dp[i-1][0]){
            if(abs(a[i]-a[i-1])<=k){
                dp[i][0]=true;
            }
            if(abs(b[i]-a[i-1])<=k){
                dp[i][1]=true;
            }
        }
        if(dp[i-1][1]){
            if(abs(a[i]-b[i-1])<=k){
                dp[i][0]=true;
            }
            if(abs(b[i]-b[i-1])<=k){
                dp[i][1]=true;
            }
        }
    }
    if(dp[n][0] || dp[n][1]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}
/*
dp
dp[i][0/1] = true if we can construct subarray from the first i elements by choosing a[i]/b[i] for the ith element
do state transition only when dp[i][0/1] is true, otherwise we will get WA on cases like:
"not possible to construct array from the first i elements, but we have |X[i]-X[i+1]| <= k"
*/