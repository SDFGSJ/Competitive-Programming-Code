#include<bits/stdc++.h>
using namespace std;
int deg[55];
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++,deg[v]++;
    }
    for(i=1;i<=n;i++){
        printf("%d\n",deg[i]);
    }
    return 0;
}