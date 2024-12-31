#include<bits/stdc++.h>
using namespace std;
char s[500010],t[500010];
deque<char> S,T;
int main(){
    int k;
    scanf("%d%s%s",&k,s,t);
    int slen=strlen(s), tlen=strlen(t);
    for(int i=0;i<slen;i++){
        S.emplace_back(s[i]);
    }
    for(int i=0;i<tlen;i++){
        T.emplace_back(t[i]);
    }

    while(!S.empty() && !T.empty() && S.front()==T.front()){
        S.pop_front();T.pop_front();
    }
    while(!S.empty() && !T.empty() && S.back()==T.back()){
        S.pop_back();T.pop_back();
    }
    if(S.size()>=2 || T.size()>=2){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}
/*
deque
simpler than 2 pointer simulation
*/