#include<bits/stdc++.h>
using namespace std;
char s[200010];
bool isabc(int idx){
    if(idx<0){
        return false;
    }
    return s[idx]=='A' && s[idx+1]=='B' && s[idx+2]=='C';
}
int main(){
    int n,q;
    scanf("%d%d%s",&n,&q,s);

    int cnt=0;
    set<int> pos;
    for(int i=0;i+2<n;i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
            pos.emplace(i);
            cnt++;
        }
    }

    while(q--){
        int x;char c;
        scanf("%d %c",&x,&c);
        x--;
        if(s[x]!=c){
            int before=isabc(x-2)+isabc(x-1)+isabc(x);
            s[x]=c;
            int after=isabc(x-2)+isabc(x-1)+isabc(x);
            cnt+=after-before;
        }
        printf("%d\n",cnt);
    }
    return 0;
}