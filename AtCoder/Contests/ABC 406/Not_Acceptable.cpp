#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(c<a){
        printf("Yes\n");
    }else if(c>a){
        printf("No\n");
    }else{
        if(d<=b){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}