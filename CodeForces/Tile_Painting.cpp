#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,copy,i;
    bool isprime=true;
    map<long long,int> m;   //<divisor,cnt>
    scanf("%lld",&n);

    copy=n;
    for(i=2;i*i<=copy;i++){
        while(copy%i==0){
            isprime=false;
            m[i]++;
            copy/=i;
        }
    }
    if(copy!=1){    //neglect 1
        m[copy]++;
    }

    if(isprime){
        printf("%lld\n",n);
    }else if(m.size()==1){  //n is a power of k
        printf("%lld\n",m.begin()->first);
    }else{
        printf("1\n");
    }
    return 0;
}