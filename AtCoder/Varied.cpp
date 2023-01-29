#include<bits/stdc++.h>
using namespace std;
char s[30];
int cnt[26];
int main(){
    int i;
    bool good=true;
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        cnt[s[i]-'a']++;
    }
    for(i=0;i<26;i++){
        if(cnt[i]>=2){
            good=false;
        }
    }
    if(good){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}