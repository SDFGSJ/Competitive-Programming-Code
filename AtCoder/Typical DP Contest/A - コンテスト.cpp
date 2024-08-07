#include<bits/stdc++.h>
using namespace std;
int a[105],dp[10005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=10000;j>=0;j--){
            if(dp[j]==1){
                dp[j+a[i]]=1;
            }
        }
    }

    int ans=0;
    for(int i=0;i<=10000;i++){
        ans+=dp[i];
    }
    printf("%d\n",ans);
    return 0;
}
/*
dp[i] = 1 <=> total sum = i is achievable
*/