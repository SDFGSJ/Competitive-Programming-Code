#include<bits/stdc++.h>
using namespace std;
bool visited[100010];
vector<int> g[100010];
vector<int> group[100010];
int stamp;
/*
give each connected component a stamp,
vertexes in the same CC, their group[i] will be the same
*/
void dfs(int now){
    if(visited[now]){
        return;
    }

    visited[now]=true;
    group[stamp].push_back(now);
    for(auto neigh:g[now]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
}
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;    //0-indexed
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //dfs every CC
    for(i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            stamp++;
        }
    }

    //need stamp-1 roads, take the first vertex of each CC
    printf("%d\n",stamp-1);
    for(i=0;i+1<stamp;i++){
        printf("%d %d\n",group[i][0]+1,group[i+1][0]+1);
    }
    return 0;
}