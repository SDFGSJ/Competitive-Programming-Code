#include<bits/stdc++.h>
using namespace std;
char str[105];
char hello[10]="hello";
int main(){
    scanf("%s",str);
    int i,idx=0;
    for(i=0;str[i]!='\0' && idx!=5;i++){
        if(str[i]==hello[idx]){
            idx++;
        }
    }
    if(idx==5){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}