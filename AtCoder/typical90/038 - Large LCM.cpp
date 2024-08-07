#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long gcd=__gcd(a,b);
    if(min(a,b)/gcd*gcd > (long long)1e18/(max(a,b)/gcd)){
        printf("Large\n");
    }else{
        printf("%lld\n",gcd*(a/gcd)*(b/gcd));
    }
    return 0;
}