#include<bits/stdc++.h>
using namespace std;
long long cost[405][405];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cost[i][j]=INT_MAX;
            if(i==j){
                cost[i][j]=0;
            }
        }
    }

    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        cost[a][b]=c;
    }

    long long ans=0;
    for(int k=1;k<=n;k++){
        for(int from=1;from<=n;from++){
            for(int to=1;to<=n;to++){
                cost[from][to]=min(cost[from][to], cost[from][k]+cost[k][to]);
                if(cost[from][to]!=INT_MAX){
                    ans+=cost[from][to];
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
//floyd warshall