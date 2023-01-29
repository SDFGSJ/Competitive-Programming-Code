#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int k,i;
    scanf("%d%s",&k,s);
    int len=strlen(s);
    if(len<=k){
        printf("%s",s);
    }else{
        for(i=0;i<k;i++){
            printf("%c",s[i]);
        }
        printf("...");
    }
    return 0;
}