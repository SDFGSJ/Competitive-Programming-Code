#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    int a=1,b=1,c=0;
    for(int i=3;i<=n;i++){
        c=(a+b)%mod;
        a=b,b=c;
    }
    printf("%d\n",c);
}