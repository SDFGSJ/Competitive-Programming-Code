#include<bits/stdc++.h>
using namespace std;
char str[105];
int main(){
    int i;
    bool yes=false;
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='H' || str[i]=='Q' || str[i]=='9'){
            yes=true;
            break;
        }
    }
    if(yes){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}