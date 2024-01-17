#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<32;i++){
        if((n&-n) & (1<<i)){
            break;
        }
    }
    printf("%d\n",i);
    return 0;
}