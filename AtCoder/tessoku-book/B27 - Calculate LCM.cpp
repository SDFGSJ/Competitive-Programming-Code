#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",a*b/__gcd(a,b));
    return 0;
}