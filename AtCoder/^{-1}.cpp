#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,num,i;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(num==x){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}