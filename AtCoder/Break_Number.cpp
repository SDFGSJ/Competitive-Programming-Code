#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num=1;
    scanf("%d",&n);
    while(num*2 <= n){
        num*=2;
    }
    printf("%d\n",num);
    return 0;
}