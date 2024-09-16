#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool dp[105][10010];
int backtrack[105][10010];
int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }

    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=10000;j>=0;j--){
            if(dp[i-1][j]){
                dp[i][j+a[i]]=true;
                backtrack[i][j+a[i]]=1;

                dp[i][j+b[i]]=true;
                backtrack[i][j+b[i]]=2;
            }
        }
    }

    if(!dp[n][s]){
        printf("No\n");
        return 0;
    }

    printf("Yes\n");
    vector<char> ans(n+1,'H');
    int sum=s;
    for(int i=n;i>=0;i--){
        if(backtrack[i][sum]==1){
            sum-=a[i];
        }else{
            ans[i]='T';
            sum-=b[i];
        }
    }
    for(int i=1;i<ans.size();i++){
        printf("%c",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
dp[i][j] = true <=> from elements 1~i, we can have sum = j
backtrack[i][j] = 1/2 <=> from elements 1~i, we can have sum = j by choosing a[i]/b[i]
*/