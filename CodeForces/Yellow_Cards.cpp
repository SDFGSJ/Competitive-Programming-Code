#include<bits/stdc++.h>
using namespace std;
int main(){
    int a1,a2,k1,k2,total;
    int least=0,m=0,M=0;
    scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&total);

    //min
    least=a1*(k1-1)+a2*(k2-1);
    m=max(total-least,0);

    //max
    /*if(k1<k2){
        M+=min(total/k1,a1);
        total-=min(total/k1,a1)*k1;
        M+=total/k2;
    }else{
        M+=min(total/k2,a2);
        total-=min(total/k2,a2)*k2;
        M+=total/k1;
    }*/
    if(k1<k2){
        if(total<=a1*k1){
            M=total/k1;
        }else{
            M=a1+(total-a1*k1)/k2;
        }
    }else{
        if(total<=a2*k2){
            M=total/k2;
        }else{
            M=a2+(total-a2*k2)/k1;
        }
    }
    printf("%d %d\n",m,M);
    return 0;
}