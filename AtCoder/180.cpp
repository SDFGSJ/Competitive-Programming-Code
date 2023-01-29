#include<bits/stdc++.h>
using namespace std;
char str[100010];
int main(){
    int len,i;
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1;i>=0;i--){
        if(str[i]=='6'){
            printf("9");
        }else if(str[i]=='9'){
            printf("6");
        }else{
            printf("%c",str[i]);
        }
    }    
    return 0;
}