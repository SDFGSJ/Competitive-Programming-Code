#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld\n",min({(a-a/2 - a/2)*b*c, a*(b-b/2 - b/2)*c, a*b*(c-c/2 - c/2)}));
    return 0;
}
/*
try all 3 axis and cut in half
*/