#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    scanf("%d",&a);
    if(400%a!=0){
        printf("-1\n");
    }else{
        printf("%d\n",400/a);
    }
    return 0;
}