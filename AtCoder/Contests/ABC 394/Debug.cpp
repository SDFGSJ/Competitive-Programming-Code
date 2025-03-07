#include<bits/stdc++.h>
using namespace std;
char s[300010];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    for(int i=len-1;i-1>=0;i--){
        if(s[i]=='A' && s[i-1]=='W'){
            s[i-1]='A',s[i]='C';
        }
    }
    printf("%s\n",s);
    return 0;
}
/*
replace the word from the back
*/