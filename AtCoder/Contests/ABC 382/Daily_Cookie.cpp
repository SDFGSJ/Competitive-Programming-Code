#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int n,d;
    scanf("%d%d%s",&n,&d,s);

    int cookie=0,empty=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='@'){
            cookie++;
        }else{
            empty++;
        }
    }
    printf("%d\n",empty+d);
    return 0;
}