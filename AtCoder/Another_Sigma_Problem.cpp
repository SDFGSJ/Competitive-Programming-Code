#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[200010];
long long prea[200010];   //prefix sum of a[]
int digit[200010],predigit[15][200010]; //prefix sum of digit[]
long long tenpow[15];   //tenpow[i] = (10^i) % mod
int num_of_digits(int num){
    int res=0;
    while(num){
        num/=10;
        res++;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        digit[i]=num_of_digits(a[i]);
    }

    for(int i=1;i<=n;i++){
        prea[i]=prea[i-1]+a[i];
    }

    for(int num=1;num<=10;num++){
        for(int i=1;i<=n;i++){
            predigit[num][i]=predigit[num][i-1];
            if(digit[i]==num){
                predigit[num][i]++;
            }
        }
    }

    tenpow[0]=1;
    for(int i=1;i<=10;i++){
        tenpow[i]=(tenpow[i-1]*10)%mod;
    }

    long long ans=0;
    for(int i=1;i+1<=n;i++){
        ans+=prea[n]-prea[i];   //the y part of f(x,y)
        ans%=mod;
        for(int num=1;num<=10;num++){   //the x part of f(x,y), calc them by # of digits
            int cnt=predigit[num][n]-predigit[num][i];
            ans+=(1ll * a[i] * ((1ll * cnt * tenpow[num]) % mod) % mod);
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
prefix sum
for each i, calc a[i]'s contribution to the ans
f(x,y) = x*10^d(y) + y, where d(y) = # of digits in y
use preifx sum to calc inner sigma
use prefix sum[d][idx] to maintain the # of element with d digits in [1,idx]
*/