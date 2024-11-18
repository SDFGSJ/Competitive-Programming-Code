#include<bits/stdc++.h>
using namespace std;
int color[100010],cnt[100010];
vector<int> Tree[100010],ans;
void dfs(int u,int parent=-1){
    cnt[color[u]]++;
    if(cnt[color[u]]==1){
        ans.emplace_back(u);
    }
    for(auto v:Tree[u]){
        if(v!=parent){
            dfs(v,u);
        }
    }
    cnt[color[u]]--;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&color[i]);
    }

    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Tree[a].emplace_back(b);
        Tree[b].emplace_back(a);
    }

    dfs(1);
    sort(ans.begin(),ans.end());
    for(auto num:ans){
        printf("%d\n",num);
    }
    return 0;
}
/*
color[i] = the color of node i
cnt[i] = # of node with color i in current path
dfs + maintain the # of each color along the path from 1 to u using global array cnt[100010]

we can declare a bool[100010] and mark good node as true to avoid sorting in ans vector
*/