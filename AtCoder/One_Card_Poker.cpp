#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==1){
        a=14;
    }
    if(b==1){
        b=14;
    }
    if(a>b){
        printf("Alice");
    }else if(a<b){
        printf("Bob");
    }else{
        printf("Draw");
    }
    return 0;
}