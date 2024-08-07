#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],dp[100010],prede[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=3;i<=n;i++){
        scanf("%d",&b[i]);
    }
    dp[1]=0;dp[2]=a[2];
    prede[1]=-1,prede[2]=1;
    for(int i=3;i<=n;i++){
        if(dp[i-1]+a[i] > dp[i-2]+b[i]){
            dp[i]=dp[i-2]+b[i];
            prede[i]=i-2;
        }else{
            dp[i]=dp[i-1]+a[i];
            prede[i]=i-1;
        }
    }

    vector<int> path;
    int now=n;
    while(now!=-1){
        path.emplace_back(now);
        now=prede[now];
    }

    printf("%ld\n",path.size());
    for(int i=path.size()-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("\n");
    return 0;
}