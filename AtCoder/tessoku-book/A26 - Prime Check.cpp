#include<bits/stdc++.h>
using namespace std;
bool isprime(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        if(isprime(x)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}