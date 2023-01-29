#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
    int i;
    bool palindrome=true;
    scanf("%s",s);
    int len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]!=s[len-1-i]){
            palindrome=false;
        }
    }
    if(palindrome){
        printf("0\n");
    }else{
        printf("3\n");
        printf("L 2\n");
        len+=1;
        printf("R 2\n");
        len=len+(len-2);
        printf("R %d\n",len-1);
    }
    return 0;
}