#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x,cnt=0,i,j,k;
    scanf("%d%d%d%d",&a,&b,&c,&x);
    for(i=0;i<=a;i++){
        for(j=0;j<=b;j++){
            for(k=0;k<=c;k++){
                if(500*i+100*j+50*k==x){
                    cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}