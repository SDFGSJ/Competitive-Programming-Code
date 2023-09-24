#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num,prev=-1;
    scanf("%d",&n);
    bool ok=true;

    while(n>0){
        num=n%10;
        if(num<=prev){
            ok=false;
        }
        prev=num;
        n/=10;
    }
    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}