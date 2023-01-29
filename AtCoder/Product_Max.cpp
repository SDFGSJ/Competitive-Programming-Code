#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    printf("%lld",max({a*c,a*d,b*c,b*d}));
    return 0;
}