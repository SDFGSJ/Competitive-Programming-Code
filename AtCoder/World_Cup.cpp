#include<bits/stdc++.h>
using namespace std;
int main(){
    int y;
    scanf("%d",&y);
    if(y%4<=2){
        printf("%d",y+2-y%4);
    }else{
        printf("%d",y+3);
    }
    return 0;
}