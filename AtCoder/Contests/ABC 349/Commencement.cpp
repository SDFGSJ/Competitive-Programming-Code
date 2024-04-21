#include<bits/stdc++.h>
using namespace std;
char str[105];
int cnt[30];
map<int,vector<char>> m;
int main(){
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        cnt[str[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]!=0){
            m[cnt[i]].emplace_back('a'+i);
        }
    }
    for(auto [k,v]:m){
        if(v.size()!=0 && v.size()!=2){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}