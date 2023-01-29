#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,cnt=0,i;
    scanf("%d%d",&a,&b);
    for(i=a;i<=b;i++){  //mnopq
        int m=i/10000;
        int n=(i%10000)/1000;
        int o=(i%1000)/100;
        int p=(i%100)/10;
        int q=i%10;
        if(m==q && n==p){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}