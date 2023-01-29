#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,hundred;
    scanf("%d",&n);
    
    hundred=n/100;
    if(n>hundred*111){
        printf("%d\n",(hundred+1)*111);
    }else{
        printf("%d\n",hundred*111);
    }
    return 0;
}