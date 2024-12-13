#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int n,d;
    scanf("%d%d%s",&n,&d,s);

    int len=strlen(s);
    for(int i=len-1;d>0;i--){
        if(s[i]=='@'){
            s[i]='.';
            d--;
        }
    }
    printf("%s\n",s);
    return 0;
}