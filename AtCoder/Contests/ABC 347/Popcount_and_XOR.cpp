#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    long long c;
    scanf("%d%d%lld",&a,&b,&c);
    int cpopcnt=__builtin_popcountll(c);

    if(min(a,b)==0 && max(a,b)==cpopcnt){
        if(a==0){
            printf("%d %lld\n",0,c);
        }else{
            printf("%lld %d\n",c,0);
        }
        return 0;
    }else if(min(a,b)==0 && max(a,b)!=cpopcnt){
        printf("-1\n");
        return 0;
    }

    long long resulta=0,resultb=0;
    int num=a+b-cpopcnt;
    if(num>=0 && num%2==0){
        int i;
        int aones=0,bones=0;
        for(i=0;i<60 && aones < num/2 && bones < num/2;i++){
            if((c & (1ll<<i))==0){  //can put 1
                resulta+=(1ll<<i);
                resultb+=(1ll<<i);
                aones++,bones++;
            }
        }

        int shift=0;
        while(bones<b && shift<60){
            if(c&(1ll<<shift)){
                resultb+=1ll<<shift;
                bones++;
            }
            shift++;
        }
        while(aones<a && shift<60){
            if(c&(1ll<<shift)){
                resulta+=1ll<<shift;
                aones++;
            }
            shift++;
        }
        if(aones!=a || bones!=b || (resulta^resultb)!=c){
            printf("-1\n");
        }else{
            printf("%lld %lld\n",resulta,resultb);
        }
    }else{
        printf("-1\n");
    }
    return 0;
}