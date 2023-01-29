#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int num=1;
        while(num<n){
            num=num<<1;
        }
        if(num!=n){
            num>>=1;
        }
        printf("%d\n",num-1);
    }
    return 0;
}