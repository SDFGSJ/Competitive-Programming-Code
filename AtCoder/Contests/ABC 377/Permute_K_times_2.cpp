#include<bits/stdc++.h>
using namespace std;
int p[200010],ans[200010];
bool vis[200010];
vector<int> a[200010];
long long mypow(long long a,long long b,int mod){
    long long result=1;
    while(b){
        if(b&1){
            result=(result*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return result;
}
int main(){
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }

    for(int i=1;i<=n;i++){
        if(i!=p[i] && !vis[i]){
            int idx=i;
            vis[i]=true;
            a[i].emplace_back(i);
            while(p[idx]!=i){
                vis[p[idx]]=true;
                a[i].emplace_back(p[idx]);
                idx=p[idx];
            }
        }else{
            ans[i]=i;
        }
    }

    for(int i=1;i<=n;i++){
        int sz=a[i].size();
        if(sz==0){
            continue;
        }
        long long exp=mypow(2ll,k,sz);
        for(int j=0;j<a[i].size();j++){
            int ansidx=a[i][j];
            ans[ansidx]=a[i][(j+exp)%sz];
        }
    }

    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
a[i] = list of nodes of a cycle starting at node i
P = [a,b,c]
after 1 permu => P'[i] = P[P[i]] = P^2[i]
after 2 permu => P''[i] = P'[P'[i]] = P'[P[P[i]]] = P[P[P[P[i]]]] = P^4[i]
after k permu => P^k[i]
find the cycle
*/