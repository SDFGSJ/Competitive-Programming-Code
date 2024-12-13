#include<bits/stdc++.h>
using namespace std;
int a[100010];
long long dp[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    a[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        if(a[i]>a[i-1]){
            dp[i]+=dp[i-1];
        }
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i];
    }
    printf("%lld\n",ans);
    return 0;
}
/*
dp[i] = # of strictly increasing subarrays that ends at idx i
dp[i] = 1 for every i initially, since i itself can be a strictly increasing subarray of size 1
if a[i]>a[i-1], then add dp[i-1] to dp[i]

**this problem can also be solved by using two pointers**
*/