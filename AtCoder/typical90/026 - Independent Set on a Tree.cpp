#include<bits/stdc++.h>
using namespace std;
vector<int> Tree[100010];
int color[100010];
bool dfs(int u,int c = 1){
    if(color[u]){
        return color[u]==c;
    }
    color[u]=c;
    for(auto v:Tree[u]){
        if(!dfs(v,-c)){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Tree[a].emplace_back(b);
        Tree[b].emplace_back(a);
    }

    dfs(1);
    int ones=0;
    for(int i=1;i<=n;i++){
        if(color[i]==1){
            ones++;
        }
    }

    int c;
    if(ones>n-ones){
        c=1;
    }else{
        c=-1;
    }

    for(int cnt=0,i=1;cnt<n/2 && i<=n;i++){
        if(color[i]==c){
            printf("%d ",i);
            cnt++;
        }
    }
    printf("\n");
    return 0;
}