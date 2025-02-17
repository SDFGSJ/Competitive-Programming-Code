#include<bits/stdc++.h>
using namespace std;
bool isprime[3000010];
vector<long long> primes;
void eratosthenes(){
    for(int i=2;i<=3000000;i++){
        isprime[i]=true;
    }
    for(int i=2;i<=3000000;i++){
        if(isprime[i]){
            primes.emplace_back(i);
            for(int j=i+i;j<=3000000;j+=i){
                isprime[j]=false;
            }
        }
    }
}
long long find_sqrt(long long num){
    long long L=0,R=3e9;
    while(L+1<R){
        long long mid=L+(R-L)/2;
        if(mid*mid<num){
            L=mid;
        }else{
            R=mid;
        }
    }
    return R;
}
int main(){
    eratosthenes();
    int t;
    scanf("%d",&t);
    while(t--){
        long long N,p=0,q=0;
        scanf("%lld",&N);
        for(auto prime:primes){
            if(N%(prime*prime)==0){
                p=prime;
                q=N/(p*p);
                break;
            }else if(N%prime==0){
                q=prime;
                p=find_sqrt(N/q);
                break;
            }
        }
        printf("%lld %lld\n",p,q);
    }
    return 0;
}
/*
# of divisors is few + eratos
since N can be represented by p*p*q(suppose p<q), where p,q are both primes
so the divisors of N are: 1,p,q,pp,pq,ppq
we only enumerate prime numbers from small to large, and we will meet either p or q before meeting pp,pq,ppq
so if N is divisible by prime*prime, then p must be "prime" and q = N/(p*p)
else if N is divisible by prime, then q must be "prime" and p = sqrt(N/q)
use bs(L=0,R=3e9) to find sqrt
*/