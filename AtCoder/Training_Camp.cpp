#include<bits/stdc++.h>
using namespace std;
const int mod = (int)1e9+7;
int main(){
    int n,i;
    long long num=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        num*=i;
        num%=mod;
    }
    printf("%lld\n",num);
    return 0;
}