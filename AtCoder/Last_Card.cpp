#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,a;
    scanf("%d%d%d",&n,&k,&a);
    if(n==1){
        printf("1\n");
    }else{
        if(a-1+k%n>n){
            printf("%d\n",a - 1 + k%n - n);
        }else{
            printf("%d\n",a - 1 + k%n);
        }
    }
    return 0;
}