#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    for(int i=1;i<=n;i++){
        sort(G[i].begin(),G[i].end());
        printf("%d: {",i);
        for(int j=0;j<G[i].size();j++){
            printf("%d",G[i][j]);
            if(j!=G[i].size()-1){
                printf(", ");
            }
        }
        printf("}\n");
    }
    return 0;
}