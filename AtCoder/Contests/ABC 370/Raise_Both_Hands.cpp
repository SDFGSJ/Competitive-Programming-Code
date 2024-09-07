#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    scanf("%d%d",&l,&r);
    if((l^r)==1){
        if(l==1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }else{
        printf("Invalid\n");
    }
    return 0;
}