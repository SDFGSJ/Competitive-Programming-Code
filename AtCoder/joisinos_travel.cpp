#include<bits/stdc++.h>
using namespace std;
int R[10];
long long dist[205][205];
int main(){
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<r;i++){
        scanf("%d",&R[i]);
    }
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        dist[a][b]=dist[b][a]=c;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    sort(R,R+r);
    long long ans=LONG_LONG_MAX;
    do{
        long long cur=0;
        for(int i=0;i+1<r;i++){
            cur+=dist[R[i]][R[i+1]];
        }
        ans=min(ans,cur);
    }while(next_permutation(R,R+r));
    printf("%lld\n",ans);
    return 0;
}
/*
floyd warshall + all permutation
*/