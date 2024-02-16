#include<bits/stdc++.h>
using namespace std;
char str[65];
int main(){
    long long n;
    scanf("%s%lld",str,&n);

    int len=strlen(str);
    long long num=0;
    for(int i=0;i<len;i++){
        if(str[i]!='?'){
            long long digit=(str[i]-'0');   //must convert to ll, otherwise left shift will overflow
            num+=(digit<<(len-1-i));
        }
    }

    if(num>n){
        printf("-1\n");
        return 0;
    }

    for(int i=0;i<len;i++){
        if(str[i]=='?'){
            if(num + (1ll << (len-1-i))>n){
                str[i]='0';
            }else{
                str[i]='1';
                num+=(1ll << (len-1-i));
            }
        }
    }
    printf("%lld\n",num);
    return 0;
}