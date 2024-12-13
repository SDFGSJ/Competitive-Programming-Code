#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    scanf("%lld",&N);
    long long ans=0;
    for(long long len=1;len*len+len<=2*N;len++){
        if(2*N%len){
            continue;
        }
        long long rhs=2*N/len-len+1;
        if(rhs%2==0 && rhs/2>=1){
            ans+=2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
suppose the progression start from n with length len => n, n+1, ..., n+len-1
sum = len(2n+len-1)/2 = N
=> 2n = 2N/len - len + 1
in order for n to be int, 2N must be multiple of len && RHS is even
if n>=1, we can always find 2 progressions whose sums are both N
one is [n, n+1, ..., n+len-1], the other is [-(n-1)...0...(n-1), n, n+1, ..., n+len-1]
in order to have n>=1, the terminating condition of for loop is "2n = 2N/len - len + 1 >= 2"
=> 2N >= len*len+len
*/