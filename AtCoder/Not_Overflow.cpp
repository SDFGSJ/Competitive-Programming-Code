#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    if(-(1ll<<31)<=n && n<=(1ll<<31)-1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}