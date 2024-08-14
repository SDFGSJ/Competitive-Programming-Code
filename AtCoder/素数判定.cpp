#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    bool isprime=true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            isprime=false;
            break;
        }
    }

    if(n==1){
        printf("Not Prime\n");
        return 0;
    }

    if(isprime || (n%2!=0 && n%5!=0 && n%3!=0)){
        printf("Prime\n");
    }else{
        printf("Not Prime\n");
    }
    return 0;
}