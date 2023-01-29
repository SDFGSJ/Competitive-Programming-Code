#include<bits/stdc++.h>
using namespace std;
int a[105],dp[1000010]; //dp[i] = the min num of coins required for sum=i
int main(){
    int n,target,i,j;
    scanf("%d%d",&n,&target);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    dp[0]=0;    //base case
    for(i=1;i<=target;i++){
        dp[i]=INT_MAX/2;    //set to big number as default
        for(j=0;j<n;j++){
            if(i-a[j]>=0){
                dp[i]=min(dp[i], dp[i-a[j]]+1);
            }
        }
    }

    if(dp[target]==INT_MAX/2){  //impossible to produce target
        printf("-1\n");
    }else{
        printf("%d\n",dp[target]);
    }
    return 0;
}