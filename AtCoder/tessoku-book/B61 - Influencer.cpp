#include<bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    int maxdeg=0,ans=0;
    for(int i=1;i<=n;i++){
        if(G[i].size()>maxdeg){
            maxdeg=G[i].size();
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}