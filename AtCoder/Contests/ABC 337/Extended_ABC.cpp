#include<bits/stdc++.h>
using namespace std;
char str[105];
int main(){
    scanf("%s",str);
    int len=strlen(str);

    string s="";
    int cnt=0;
    for(int i=0;i+1<len;i++){
        if(str[i]!=str[i+1]){
            cnt++;
            if(s==""){
                s+=str[i];
                s+=str[i+1];
            }else{
                s+=str[i+1];
            }
        }
    }
    if(cnt==0){
        printf("Yes\n");
    }else if(cnt==1){
        if(s[0]<s[1]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }else if(cnt==2){
        if(s!="ABC"){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }else{
        printf("No\n");
    }
    return 0;
}