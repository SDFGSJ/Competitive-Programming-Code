#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long mypow(long long a,long long b){
    long long res=1ll;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    if(2*y-x<0 || (2*y-x)%3!=0 || 2*x-y<0 || (2*x-y)%3!=0){ //since a,b are both >=0 and integer
        printf("0\n");
        return 0;
    }

    int a=(2*y-x)/3, b=(2*x-y)/3;
    long long nomi=1ll,a_fac=1ll,b_fac=1ll,denomi=1ll;
    for(int i=1;i<=a+b;i++){
        nomi=(nomi*i)%mod;
        if(i<=a){
            a_fac=(a_fac*i)%mod;
        }
        if(i<=b){
            b_fac=(b_fac*i)%mod;
        }
    }
    denomi=(a_fac*b_fac)%mod;

    printf("%lld\n",nomi*mypow(denomi,mod-2)%mod);  //(nomi/denomi)%mod
    return 0;
}
/*
let op1 be (i,j)->(i+1,j+2), op2 be (i,j)->(i+2,j+1)
suppose there are a's op1 and b's op2
(X,Y) = a(1,2) + b(2,1) = (a+2b,2a+b) => (a,b)=((2Y-X)/3, (2X-Y)/3)
check whether a,b are >=0 and both int
ans = ((a+b)! / a!b! ) % mod
*/