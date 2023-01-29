#include<bits/stdc++.h>
using namespace std;
char s[25];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    if(s[len-1]=='r'){
        printf("er\n");
    }else{
        printf("ist\n");
    }
    return 0;
}