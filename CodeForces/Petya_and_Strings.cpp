#include<bits/stdc++.h>
using namespace std;
char str1[105],str2[105];
int main(){
    int i;
    scanf("%s%s",str1,str2);
    for(i=0;str1[i]!='\0' && str2[i]!='\0';i++){
        str1[i]=tolower(str1[i]);
        str2[i]=tolower(str2[i]);
        if(str1[i]<str2[i]){
            printf("-1\n");
            break;
        }else if(str1[i]>str2[i]){
            printf("1\n");
            break;
        }
    }
    if(str1[i]=='\0'){
        printf("0\n");
    }
}