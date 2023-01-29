#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int i,j;
    bool danger=false;
    scanf("%s",s);
    int len=strlen(s);
    for(i=0;i<len;){
        for(j=i;j<len;j++){
            if(s[j]!=s[i]){
                break;
            }
        }
        if(j-i>=7){
            danger=true;
            break;
        }
        i=j;
    }
    if(danger){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}