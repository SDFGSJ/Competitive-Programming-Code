#include<bits/stdc++.h>
using namespace std;
int num_of_factor(long long num){
    int cnt=0;
    for(long long i=2;i*i<=num;i++){
        if(num%i==0){
            cnt++;
            while(num%i==0){
                num/=i;
            }
        }
    }
    if(num!=1){
        cnt++;
    }
    return cnt;
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long gcd=__gcd(a,b);
    printf("%d\n",num_of_factor(gcd)+1);
    return 0;
}
/*
gcd + factorization
find gcd(a,b) and factorize it into p1^e1 + p2^e2 + ... + pn^en
then ans = 1+(# of different prime factors of gcd) = n+1
where 1 is for prime factor 1, since 1 coprimes with every number
ex. 60 = 2^2 * 3 * 5 => ans=3+1=4
*/