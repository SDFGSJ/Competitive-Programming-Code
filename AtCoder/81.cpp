#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);

    bool good=false;
    for(i=1;i<=9;i++){
        if(n%i==0 && n/i<=9){
            good=true;
        }
    }

    if(good){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}