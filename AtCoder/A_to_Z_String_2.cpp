#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    if(x%n==0){
        printf("%c\n",'A' + x/n - 1);
    }else{
        printf("%c\n",'A' + x/n);
    }
    return 0;
}