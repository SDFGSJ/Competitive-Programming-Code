#include<bits/stdc++.h>
using namespace std;
char str[200010];
int main(){
    int a,z,len,i;
    scanf("%s",str);
    
    len=strlen(str);
    a=z=0;
    for(i=0;i<len;i++){
        if(str[i]=='A'){
            a=i;
            break;
        }
    }
    for(i=len-1;i>=0;i--){
        if(str[i]=='Z'){
            z=i;
            break;
        }
    }
    printf("%d\n",z-a+1);
    return 0;
}