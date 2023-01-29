#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(abs(a-b)==0){
            printf("0 0\n");
        }else if(abs(a-b)==1){
            printf("1 0\n");
        }else{
            long long gcd=abs(a-b),bigger=0,smaller=0;
            if(a%gcd==0){
                bigger=smaller=a;
            }else{
                bigger=(a/gcd+1)*gcd;
                smaller=(a/gcd)*gcd;
            }
            //printf("gcd=%lld,bigger=%lld,smaller=%lld\n",gcd,bigger,smaller);
            printf("%lld %lld\n",gcd,min({bigger-a,a-smaller,a,b}));
        }
    }
    return 0;
}