#include<bits/stdc++.h>
using namespace std;
int h[100010],dp[100010],prede[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }

    dp[1]=0;
    dp[2]=abs(h[2]-h[1]),prede[2]=1;
    for(int i=3;i<=n;i++){
        int one=dp[i-1]+abs(h[i-1]-h[i]);
        int two=dp[i-2]+abs(h[i-2]-h[i]);
        if(one > two){
            dp[i]=two;
            prede[i]=i-2;
        }else{
            dp[i]=one;
            prede[i]=i-1;
        }
    }

    vector<int> ans;
    for(int now=n;now!=0;now=prede[now]){
        ans.emplace_back(now);
    }
    printf("%ld\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}