#include<bits/stdc++.h>
using namespace std;
char s[200010];
int main(){
    int i,sum=0;
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        sum+=s[i]-'0';
    }
    if(sum%9){
        printf("No");
    }else{
        printf("Yes");
    }
    return 0;
}