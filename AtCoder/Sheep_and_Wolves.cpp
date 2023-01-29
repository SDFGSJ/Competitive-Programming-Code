#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,w;
    scanf("%d%d",&s,&w);
    if(s<=w){
        printf("unsafe");
    }else{
        printf("safe");
    }
    return 0;
}