#include<bits/stdc++.h>
using namespace std;
bool valid(long long mid,long long k,long long target){
    return mid*(mid-k)<target;
}
long long bs(long long k,long long target){
    long long L=0,R=1e9+1;
    while(L+1<R){
        long long mid=L+(R-L)/2;
        if(valid(mid,k,target)){
            L=mid;
        }else{
            R=mid;
        }
    }
    return R;
}
int main(){
    long long N;
    scanf("%lld",&N);

    for(long long k=1;N-k*k*k>=0;k++){  //N = x^3-y^3 = (x-y)(x^2+xy+y^2) = k(N/k)
        if(((N-k*k*k)%(3*k)) == 0){
            long long target=(N-k*k*k)/3/k;
            long long x=bs(k,target);
            if(x*(x-k)==target && x-k>0){
                printf("%lld %lld\n",x,x-k);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
/*
math + binary search
we know that N = x^3-y^3 = (x-y)(x^2+xy+y^2), we let k = (x-y) => (x^2+xy+y^2) would be N/k
since N,x,y > 0 => (x^2+xy+y^2) > 0 => (x-y)=k > 0 => x must be greater than y
so the min possible value for k=(x-y) is 1
from k = (x-y), we get y = (x-k) and replace every y in (x^2+xy+y^2) with (x-k)
and we get "3*k*x*x - 3*k*k*x + k*k*k = N" => "3kx(x-k) = N-k*k*k" => "x(x-k) = (N-k*k*k)/(3k)"
since k is a const that we enumerate, we only need to check whether (N-k*k*k) can be divided by (3k)
if (N-k*k*k) can be divided by (3k), then we use bs to find the smallest x s.t. "x(x-k) >= (N-k*k*k)/(3k)"
since y need to be positive, we need to check whether y=(x-k)>0 before output
Editorial video watched
*/