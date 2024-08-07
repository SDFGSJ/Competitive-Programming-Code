#include<bits/stdc++.h>
using namespace std;
int x[1005],y[1005];
double dp[1<<16][16];
double dist(int j,int k){
    return sqrt((x[j]-x[k])*(x[j]-x[k]) + (y[j]-y[k])*(y[j]-y[k]));
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }

    //init
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=1e9;
        }
    }

    dp[0][0]=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]>=1e9){
                continue;
            }
            for(int k=0;k<n;k++){   //enumerate every city, want to go to city k
                if(i&(1<<k)){   //if this city has been visited before
                    continue;
                }
                dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k], dp[i][j]+dist(j,k));
            }
        }
    }
    printf("%.12f\n",dp[(1<<n)-1][0]);
    return 0;
}
/*
dp[i][j] = shortest path until j when already traveled set of nodes i
*/