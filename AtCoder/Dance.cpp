#include<bits/stdc++.h>
using namespace std;
int n,ans=-1;
int a[20][20],vis[20];
void dfs(int sum){
    //find the 1st unvisited index
    int idx=0;
    for(int i=1;i<=2*n;i++){
        if(!vis[i]){
            idx=i;
            break;
        }
    }

    //if everyone is paired, update the ans
    if(idx==0){
        ans=max(ans,sum);
        return;
    }

    //for each possible partner of idx, do dfs
    for(int j=idx+1;j<=2*n;j++){
        if(!vis[j]){
            vis[idx]=vis[j]=true;
            dfs(sum^a[idx][j]);
            vis[idx]=vis[j]=false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++){
        for(int j=i+1;j<=2*n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    dfs(0);
    printf("%d\n",ans);
    return 0;
}
/*
brute force enumerate
vis[i] = true if person i has already been chosen
*/