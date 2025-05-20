#include<bits/stdc++.h>
using namespace std;
int a[200010],dist[200010]; //dist[i] = dist from 1 to i
int cycle_start,cycle_len;
void dfs(int u,int dis){
    if(dist[u]!=-1){
        cycle_start=u;
        cycle_len=dis-dist[u];
        return;
    }
    dist[u]=dis;
    dfs(a[u],dis+1);
}
int main(){
    int n;long long k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dist[i]=-1;
    }

    dfs(1,0);
    int now=0;  //starting point
    if(k<dist[cycle_start]){
        now=1;
    }else{
        now=cycle_start;
        k-=dist[cycle_start];
        k%=cycle_len;
    }
    for(int i=0;i<k;i++){   //teleport directly
        now=a[now];
    }
    printf("%d\n",now);
    return 0;
}
/*
find cycle
notice that k might < cycle length, in this case, we teleport directly
*/