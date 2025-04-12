#include<bits/stdc++.h>
using namespace std;
char s[200010],t[200010];
set<char> tdist[26],sdist[26];
int main(){
    scanf("%s%s",s,t);
    for(int i=0;t[i]!='\0';i++){
        if(s[i]!=t[i]){
            tdist[t[i]-'a'].emplace(s[i]);
            sdist[s[i]-'a'].emplace(t[i]);
        }
    }

    for(int i=0;i<26;i++){
        if(tdist[i].size()>=2 || sdist[i].size()>=2){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}