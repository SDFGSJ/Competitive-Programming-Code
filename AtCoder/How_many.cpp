#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,t,cnt=0,i,j,k;
    scanf("%d%d",&s,&t);
    for(i=0;i<=s;i++){
        for(j=0;j<=s;j++){
            for(k=0;k<=s;k++){
                if(i+j+k<=s && i*j*k<=t){
                    cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}