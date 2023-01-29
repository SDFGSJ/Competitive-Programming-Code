#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> dp;
/*
dp[i] = the length of the longest path starting from vertex i
*/
int dfs(int now){
    if(dp[now]){    //memoization
        return dp[now];
    }
    
    //visit all the neighbors connected to now
    for(auto i:v[now]){
        dp[now] = max(dp[now], dfs(i)+1);
    }
    return dp[now];
}
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);

    v.resize(n);
    dp.resize(n);
    
    //initialize & base case(out degree = 0 => dp[i] = 0)
    for(i=0;i<n;i++){
        dp[i]=0;
    }

    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;    //0-indexed
        v[a].push_back(b);
    }

    for(i=0;i<n;i++){
        dp[i]=dfs(i);
    }

    printf("%d\n",*max_element(dp.begin(),dp.end()));
    return 0;
}