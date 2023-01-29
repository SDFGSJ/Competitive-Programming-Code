#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,a,b;
    scanf("%d%d%d",&x,&a,&b);
    if(abs(x-a)<abs(x-b)){
        printf("A");
    }else{
        printf("B");
    }
    return 0;
}