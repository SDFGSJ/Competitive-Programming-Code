#include<bits/stdc++.h>
using namespace std;
bool isprime[100010];
int pre[100010];
void eratos(){
    for(int i=2;i<=100000;i++){
        isprime[i]=true;
    }
    for(int i=2;i<=100000;i++){
        if(isprime[i]){
            for(int j=i+i;j<=100000;j+=i){
                isprime[j]=false;
            }
        }
    }
}
int main(){
    eratos();
    for(int i=1;i<=100000;i++){
        pre[i]=pre[i-1];
        if(isprime[i] && isprime[(i+1)/2]){
            pre[i]+=1;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",pre[r]-pre[l-1]);
    }
    return 0;
}
/*
eratosthenes
enumerate from 1 to n, check whether n and (n+1)/2 are both prime
then prefix sum
*/