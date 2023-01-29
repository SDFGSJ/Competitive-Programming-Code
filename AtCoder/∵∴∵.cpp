#include<bits/stdc++.h>
using namespace std;
char o[55],e[55];
int main(){
    int i,j;
    scanf("%s%s",o,e);

    for(i=0, j=0;o[i]!='\0' && e[j]!='\0';i++, j++){
        printf("%c%c",o[i],e[j]);
    }
    if(o[i]!='\0'){
        printf("%c",o[i]);
    }
    if(e[j]!='\0'){
        printf("%c",e[j]);
    }
    printf("\n");
    return 0;
}