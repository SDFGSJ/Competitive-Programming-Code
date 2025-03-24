#include<bits/stdc++.h>
using namespace std;
long long dist[305][305];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<m;i++){
        int a,b;
        long long t;
        scanf("%d%d%lld",&a,&b,&t);
        dist[a][b]=t;
        dist[b][a]=t;
    }

    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    long long ans=INT_MAX;
    for(int i=1;i<=n;i++){
        long long cur=INT_MIN;
        for(int j=1;j<=n;j++){
            cur=max(cur,dist[i][j]);
        }
        ans=min(ans,cur);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
floyd warshall
*/