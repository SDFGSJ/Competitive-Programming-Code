#include<bits/stdc++.h>
using namespace std;
vector<int> Tree[100010];
int level[100010];
void dfs(int u,int parent = -1){
    if(parent==-1){
        level[u]=0;
    }else{
        level[u]=level[parent]+1;
    }

    for(auto v:Tree[u]){
        if(v!=parent){
            dfs(v,u);
        }
    }
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
    int a=max_element(level+1,level+1+n)-level;
    dfs(a);
    int b=max_element(level+1,level+1+n)-level;
    printf("%d\n",level[b]+1);
    return 0;
}