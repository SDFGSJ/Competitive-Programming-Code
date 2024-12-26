#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int> edges[100010];   //<weight,u,v>
int sz[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[i]=make_tuple(w,u,v);
    }

    sort(edges,edges+n-1);
    for(int i=1;i<=n;i++){
        sz[i]=1;
    }

    long long ans=0;
    for(int i=0;i<n-1;i++){
        int w,u,v;
        tie(w,u,v)=edges[i];
        int usz=sz[u], vsz=sz[v];
        printf("u=%d, v=%d, w=%d, usz=%d, vsz=%d\n",u,v,w,usz,vsz);
        /*ans+=1ll*w*((usz-1)*vsz + usz*(vsz-1) + 1);*/
        ans+=1ll*w*usz*vsz;
        sz[u]+=vsz;
        sz[v]+=usz;
    }
    printf("%lld\n",ans);
    return 0;
}