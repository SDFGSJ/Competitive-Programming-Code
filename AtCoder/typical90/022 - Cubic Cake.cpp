#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    int gcd=__gcd(a,__gcd(b,c));    //gcd of a,b,c
    if(gcd!=1){
        printf("%lld\n",a/gcd + b/gcd + c/gcd - 3); //view a cube of length gcd as 1 big cube
    }else{
        printf("%lld\n",a+b+c-3);   //(a-1) + (b-1) + (c-1)
    }
    return 0;
}