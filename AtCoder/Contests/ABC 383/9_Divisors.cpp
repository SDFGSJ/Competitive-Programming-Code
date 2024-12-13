#include<bits/stdc++.h>
using namespace std;
bool isprime[2000010];
vector<long long> primes;
void eratos(){
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=2000000;i++){
        isprime[i]=true;
    }

    for(int i=2;i<=2000000;i++){
        if(isprime[i]){
            primes.emplace_back(i);
            for(int j=i+i;j<=2000000;j+=i){
                isprime[j]=false;
            }
        }
    }
}
long long myexp(long long num){
    long long res=1;
    for(int i=0;i<8;i++){
        res*=num;
    }
    return res;
}
long long find_sqrt(long long num){
    long long l=1,r=num+1;
    while(l+1<r){
        long long mid=l+(r-l)/2;
        if(mid>num/mid){
            r=mid;
        }else{
            l=mid;
        }
    }
    return l;
}
int main(){
    long long n;
    scanf("%lld",&n);

    eratos();
    long long sqrtn=find_sqrt(n);

    int ans=0;
    for(int l=0;l+1<primes.size() && primes[l]<=sqrtn;l++){
        auto it=upper_bound(primes.begin()+l+1, primes.end(), sqrtn/primes[l]);
        int cnt=it-(primes.begin()+l)-1;
        ans+=cnt;
    }

    for(auto num:primes){
        if(myexp(num)<=n){
            ans++;
        }else{
            break;
        }
    }

    printf("%d\n",ans);
    return 0;
}
/*
already seen official editoial video
*/