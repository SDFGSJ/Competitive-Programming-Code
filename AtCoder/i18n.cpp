#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    printf("%c%d%c\n",s[0],len-2,s[len-1]);
    return 0;
}