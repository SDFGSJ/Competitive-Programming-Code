#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    int a1=0,a2=0,a3=1;
    if(n==1 || n==2){
        printf("0\n");
        return 0;
    }else if(n==3){
        printf("1\n");
        return 0;
    }

    int ai=0;
    for(int i=0;i<n-3;i++){
        ai=(a3+a2+a1)%10007;
        a1=a2,a2=a3,a3=ai;
    }
    printf("%d\n",ai);
    return 0;
}
/*
simulation
*/