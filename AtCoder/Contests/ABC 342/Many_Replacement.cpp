#include<bits/stdc++.h>
using namespace std;
char str[200010];
vector<int> pos[30];
int main(){
    int n,q;
    scanf("%d%s%d",&n,str,&q);
    for(int i=0;i<n;i++){
        pos[str[i]-'a'].emplace_back(i);
    }
    while(q--){
        char c,d;
        getchar();
        scanf("%c %c",&c,&d);   //c change to d, move all num in pos[c] to pos[d]
        if(c==d){
            continue;
        }
        //cout<<c<<d<<'\n';
        if(pos[c-'a'].size()>pos[d-'a'].size()){
            swap(pos[c-'a'],pos[d-'a']);
            for(auto num:pos[c-'a']){
                pos[d-'a'].emplace_back(num);
            }
        }else{
            for(auto num:pos[c-'a']){
                pos[d-'a'].emplace_back(num);
            }
        }
        pos[c-'a'].clear();
    }
    for(int i=0;i<26;i++){
        for(auto idx:pos[i]){
            str[idx]='a'+i;
        }
    }
    printf("%s\n",str);
    return 0;
}