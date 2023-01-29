#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n,copy,last=1ll,most=0,i;
        int M=-1;
        map<long long,int> m;   //<divisor,cnt>

        scanf("%lld",&n);
        copy=n;

        for(i=2;i*i<=copy;i++){
            while(copy%i==0){
                m[i]++;
                copy/=i;
            }
        }
        m[copy]++;

        for(auto item:m){
            if(M<item.second){
                M=item.second;
                most=item.first;
            }
        }

        printf("%d\n",M);
        if(M==1){
            printf("%lld\n",n);
        }else{
            /*last*=most;
            for(auto i:m){
                if(i.first!=most){
                    last=last*(long long)pow((long double)i.first,(long double)i.second);
                }
            }*/
            copy=n;
            while(copy%most==0){
                copy/=most;
            }
            last=most*copy; //copy is the multiply of the rest of the numbers
            for(i=0;i<M-1;i++){
                printf("%lld ",most);
            }
            printf("%lld\n",last);
        }
    }
    return 0;
}