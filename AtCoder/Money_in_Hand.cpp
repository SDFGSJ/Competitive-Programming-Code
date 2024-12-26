#include<bits/stdc++.h>
using namespace std;
vector<int> coin[55];   //coin[i] = list of possible values of the i-th set of coins (Ai, Bi)
bool dp[55][10010];
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j=0;j<=b;j++){  //all possible values for Bi coins of Ai yen is 0, Ai, 2*Ai, ... Bi*Ai
            coin[i].emplace_back(a*j);
        }
    }

    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            if(dp[i-1][j]){
                for(auto val:coin[i]){
                    if(j+val<=10000){
                        dp[i][j+val]=true;
                    }
                }
            }
        }
    }
    if(dp[n][x]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
dp
dp[i][j] = true if we choose a value from each list coin[1~i], the sum of values can be j
*/