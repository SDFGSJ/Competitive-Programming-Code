#include<bits/stdc++.h>
using namespace std;
char s[100];
int cnt[26];
int main(){
    int i;
    bool bad=false;
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        cnt[s[i]-'a']++;
    }
    for(i=0;i<26;i++){
        if(cnt[i]%2){
            bad=true;
        }
    }
    if(bad){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}