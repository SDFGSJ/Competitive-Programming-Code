#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<19;i++){
        if(a+b!=i){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}