#include<bits/stdc++.h>
using namespace std;
int eratos[10000010];   //eratos[i] = # of different kind of prime factor of number i
bool vis[10000010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            for(int j=i;j<=n;j+=i){
                eratos[j]++;
                vis[j]=true;
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(eratos[i]>=k){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
eratosthenes
*/