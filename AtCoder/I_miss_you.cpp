#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int i;
    scanf("%s",s);
    int len=strlen(s);
    for(i=0;i<len;i++){
        s[i]='x';
    }
    printf("%s\n",s);
    return 0;
}