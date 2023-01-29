#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,one=0,two=0;
        scanf("%d",&n);
        if(n%3==0){
            one=two=n/3;
        }else if(n%3==1){
            one=n/3+1;
            two=n/3;
        }else{
            one=n/3;
            two=n/3+1;
        }
        printf("%d %d\n",one,two);
    }
    return 0;
}