#include<bits/stdc++.h>
using namespace std;
char str[20];
int main(){
    scanf("%s",str);
    int len=strlen(str);
    bool ok=true;
    for(int i=1;i<len;i+=2){
        if(str[i]=='1'){
            ok=false;
        }
    }
    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}