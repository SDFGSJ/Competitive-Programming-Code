#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
    int i;
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        if(i%2==0){
            printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}