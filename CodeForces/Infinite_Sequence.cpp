#include<bits/stdc++.h>
using namespace std;
int main(){
    int a1,an,d;
    scanf("%d%d%d",&a1,&an,&d);
    if(d==0){
        if(a1==an){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }else{
        if((an-a1)%d==0 && (an-a1)/d>=0){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}
