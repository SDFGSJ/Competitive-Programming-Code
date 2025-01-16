#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    a--;
    long long lcm=c*d/__gcd(c,d);
    long long coprime_with_a=a-(a/c + a/d - a/lcm);
    long long coprime_with_b=b-(b/c + b/d - b/lcm);
    printf("%lld\n",coprime_with_b-coprime_with_a);
    return 0;
}
/*
find the # of int in [a,b] s.t. int can't be divided by c and d
# of int<=num that can be divided by either c or d = num/c + num/d - num/lcm(c,d)
let f(num) = # of int in [1,num] that can't be divided by c and d
= num-(num/c + num/d - num/lcm(c,d))
then the ans will be f(b)-f(a-1)
*/