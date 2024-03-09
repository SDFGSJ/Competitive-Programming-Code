#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<bool> is_prime;
vector<int> primes;
void sieve(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            primes.emplace_back(i);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sieve(200000);
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            int after=1;
            for(auto p:primes){
                if(p>a[i]){
                    break;
                }

                int pow=0;  //factorization
                while(a[i]%p==0){
                    a[i]/=p;
                    pow++;
                }
                if(pow%2==1){
                    after*=p;
                }
            }
            if(a[i]!=1){
                after*=a[i];
            }
            a[i]=after;
        }
    }
    sort(a,a+n);    //sorting doesn't affect answer
    long long ans=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ans+=n-1-i;
        }else{
            ans+=upper_bound(a+i+1,a+n,a[i])-lower_bound(a+i+1,a+n,a[i]);   //count the number of a[i] in the range [i+1,n)
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
the array [0, 2, 3, 2^2, 2^3, (2^2)*3, 3*5] can be rewrite as [0, 2, 3, 2^0, (2^0)*3, 3*5]
since we only consider whether it's a square number or not, so if
pow % 2 == 1 => only left a pow
pow % 2 == 0 => only left 1
sort the array then the problem remains to find #(same number) in a specific range
*/