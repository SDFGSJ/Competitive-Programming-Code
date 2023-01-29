// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
using namespace std;
int n,m;
bool g[30][30];
void solve(){
    scanf("%d%d",&n,&m);
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            //only cares about corner and edges
            if(i==1 || i==n || j==1 || j==m){
                if(g[i-1][j-1]==0 && g[i-1][j]==0 && g[i-1][j+1]==0 && g[i][j-1]==0){
                    g[i][j]=1;
                }
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d",g[i][j]);
        printf("\n");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
}