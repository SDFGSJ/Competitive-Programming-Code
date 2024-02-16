#include<bits/stdc++.h>
using namespace std;
char str[500010];
map<int,int> m; //<pattern, cnt>
int main(){
    scanf("%s",str);
    int pattern=0;
    m[pattern]++;
    for(int i=0;str[i]!='\0';i++){
        pattern ^= 1<<(str[i]-'0');
        m[pattern]++;
    }

    long long ans=0;
    for(auto item:m){
        ans+=1ll*item.second*(item.second-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
ref:https://atcoder.jp/contests/abc295/editorial/6058
*/