#include<bits/stdc++.h>
using namespace std;
char s[5];
int main(){
    scanf("%s",s);
    int len=strlen(s), cnt=0;
    while(cnt!=6){
        printf("%s",s);
        cnt+=len;
    }
    return 0;
}