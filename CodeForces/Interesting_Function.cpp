#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,suma=0,sumb=0;
        scanf("%d%d",&a,&b);
        while(a > 0){
            suma+=a;
            a/=10;
        }
        //printf("suma=%d\n",suma);
        while(b > 0){
            sumb+=b;
            b/=10;
        }
        //printf("sumb=%d\n",sumb);
        printf("%d\n",sumb-suma);
    }
    return 0;
}