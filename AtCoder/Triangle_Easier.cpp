#include<bits/stdc++.h>
using namespace std;
bool adj[105][105];
int main(){
    int n,m,cnt=0,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][v]=adj[v][u]=true;
    }

    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            for(k=j+1;k<=n;k++){
                if(adj[i][j] && adj[j][k] && adj[k][i]){
                    cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}