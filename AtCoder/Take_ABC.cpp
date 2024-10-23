#include<bits/stdc++.h>
using namespace std;
char str[200010];
vector<char> s;
int main(){
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        s.emplace_back(str[i]);
        int sz=s.size();
        if(sz>=3 && s[sz-3]=='A' && s[sz-2]=='B' && s[sz-1]=='C'){
            s.pop_back();s.pop_back();s.pop_back();
        }
    }
    for(auto ch:s){
        printf("%c",ch);
    }
    printf("\n");
    return 0;
}