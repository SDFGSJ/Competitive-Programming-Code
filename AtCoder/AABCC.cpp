#include<bits/stdc++.h>
using namespace std;
vector<bool> is_prime;
vector<long long> primes,square_primes;
void sieve(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
}
int main(){
    long long n;
    scanf("%lld",&n);

    sieve(300000);
    for(long long i=2;i<=300000;i++){
        if(is_prime[i]){
            primes.emplace_back(i);
            square_primes.emplace_back(i*i);    //for c^2
        }
    }

    int ans=0;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        for(int j=i+1;j<primes.size() && primes[i]*primes[i]*primes[j]<=n;j++){
            long long target=n/(primes[i]*primes[i]*primes[j]); //c*c's maximum, that is, c*c<=target
            int cnt=upper_bound(square_primes.begin(),square_primes.end(),target)-(square_primes.begin()+j+1);  //find the first number > target
            if(cnt<=0){ //optimize, cnt will be decreasing when j becomes bigger
                break;
            }
            ans+=max(cnt,0);
        }
    }
    printf("%d\n",ans);
    return 0;
}