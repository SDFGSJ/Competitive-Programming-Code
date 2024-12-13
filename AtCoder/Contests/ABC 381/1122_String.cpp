#include<bits/stdc++.h>
using namespace std;
char s[105];
int cnt[30];
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    bool isans=true;
    for(int i=1;i<=len/2;i++){
        cnt[s[2*i-1]-'a']++;
        cnt[s[2*i]-'a']++;
        if(s[2*i-1]!=s[2*i]){
            isans=false;
        }
    }
    for(int i=0;i<26;i++){
        if(cnt[i]>2){
            isans=false;
        }
    }
    if(len%2){
        isans=false;
    }
    if(isans){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}