#include<bits/stdc++.h>
using namespace std;
long long cnt[30];
int main(){
    string s;
    cin>>s;
    long long len=s.length();
    long long ans=len*(len-1)/2;
    for(int i=0;i<len;i++){
        cnt[s[i]-'a']++;
    }
    bool multi=false;
    for(int i=0;i<26;i++){
        if(cnt[i]>=2){
            multi=true;
        }
        ans-=cnt[i]*(cnt[i]-1)/2;
    }
    if(multi){
        ans+=1;
    }
    printf("%lld\n",ans);
    return 0;
}