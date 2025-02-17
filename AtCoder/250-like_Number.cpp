#include<bits/stdc++.h>
using namespace std;
bool isprime[1000010];
vector<long long> primes;
void eratosthenes(){
    for(int i=2;i<=1000000;i++){
        isprime[i]=true;
    }
    for(int i=2;i<=1000000;i++){
        if(isprime[i]){
            primes.emplace_back(i);
            for(int j=i+i;j<=1000000;j+=i){
                isprime[j]=false;
            }
        }
    }
}
bool valid(int idx,long long N,long long p){
    long long q=primes[idx];
    return q*q*q<=N/p;
}
int main(){
    eratosthenes();
    long long N;
    scanf("%lld",&N);

    long long ans=0;
    for(int i=0;i<primes.size();i++){
        int L=i,R=primes.size();
        while(L+1<R){
            int mid=L+(R-L)/2;
            if(valid(mid,N,primes[i])){
                L=mid;
            }else{
                R=mid;
            }
        }
        ans+=L-i;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
eratosthenes + bs
enumerate p and find the last q s.t. pq^3<=N (beware of multiplication overfow), and let the index of that q be L
then there are L-i numbers that satisfy problem constraints
*/