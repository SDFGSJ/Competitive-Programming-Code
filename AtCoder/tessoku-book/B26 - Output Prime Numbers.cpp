#include<bits/stdc++.h>
using namespace std;
vector<bool> is_prime;
void eratos(int n){
    is_prime.assign(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    eratos(n);
    for(int i=1;i<=n;i++){
        if(is_prime[i]){
            printf("%d\n",i);
        }
    }
    return 0;
}