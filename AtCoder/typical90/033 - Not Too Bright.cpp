#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    if(h==1 || w==1){
        printf("%d\n",max(h,w));
    }else{
        printf("%d\n",((h+1)/2) * ((w+1)/2));
    }
    return 0;
}