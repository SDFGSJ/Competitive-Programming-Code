#include<bits/stdc++.h>
using namespace std;
const int mod=10000;
int main(){
    int n;
    scanf("%d",&n);
    int result=0;
    for(int i=0;i<n;i++){
        char t;
        int a;
        scanf(" %c%d",&t,&a);
        if(t=='+'){
            result+=a;
            result%=mod;
        }else if(t=='-'){
            result=result+mod-a;
            result%=mod;
        }else{
            result*=a;
            result%=mod;
        }
        printf("%d\n",result);
    }
    return 0;
}