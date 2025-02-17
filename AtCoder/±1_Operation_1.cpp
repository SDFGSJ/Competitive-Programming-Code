#include<bits/stdc++.h>
using namespace std;
long long solve(
    long long left,long long right,
    long long num,long long A,long long D
){
    if(num<left || num>right){  //out of range
        return min(abs(left-num), abs(right-num));
    }
    D=abs(D);   //important, D might be negative
    long long remainder=((num-left)%D+D)%D;
    return min(remainder, D-remainder);
}
int main(){
    long long X,A,D,N,ans=0;
    scanf("%lld%lld%lld%lld",&X,&A,&D,&N);
    if(D==0){
        ans=abs(X-A);
    }else{
        if(D>0){
            ans=solve(A,A+(N-1)*D,X,A,D);
        }else{
            ans=solve(A+(N-1)*D,A,X,A,D);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
beware that D might be 0
if D is 0, which means all N numbers are A, then the ans is |X-A|
if D is not 0
    if X is out of the range of S, then the ans is min(|left-X|, |right-X|)
    else we shift the left bound to 0 for easier calculation
    notice that D might be negative, so take abs value of it
    let remainder = ((X-left)%D+D)%D, then the ans is min(remainder, D-remainder)
*/