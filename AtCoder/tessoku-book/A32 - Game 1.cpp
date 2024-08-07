#include<bits/stdc++.h>
using namespace std;
bool dp[100010];
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(a>b){
        swap(a,b);
    }
    dp[a]=dp[b]=true;
    for(int i=a+1;i<=b-1;i++){
        dp[i]=!dp[i-a];
    }
    for(int i=b+1;i<=n;i++){
        dp[i]=!(dp[i-a] && dp[i-b]);
    }
    if(dp[n]){
        printf("First\n");
    }else{
        printf("Second\n");
    }
    return 0;
}
/*
dp[i] = true/false if first win/lose when there're i stones
*/