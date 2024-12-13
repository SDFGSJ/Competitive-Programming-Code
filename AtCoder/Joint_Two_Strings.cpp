#include<bits/stdc++.h>
using namespace std;
char t[500010],s[500010];
int prefix[500010],suffix[500010];
long long pre_cnt[500010],suf_cnt[500010];
int calc_longest_prefix(int slen,int tlen){
    int tidx=0;
    for(int i=0;i<slen && tidx<tlen;i++){
        if(s[i]==t[tidx]){
            tidx++;
        }
    }
    return tidx;
}
int calc_longest_suffix(int slen,int tlen){
    int tidx=tlen-1;
    for(int i=slen-1;i>=0 && tidx>=0;i--){
        if(s[i]==t[tidx]){
            tidx--;
        }
    }
    return tlen-1-tidx;
}
int main(){
    int n;
    scanf("%d%s",&n,t);
    int tlen=strlen(t);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int slen=strlen(s);

        prefix[i]=calc_longest_prefix(slen,tlen);
        suffix[i]=calc_longest_suffix(slen,tlen);
        pre_cnt[prefix[i]]++;
        suf_cnt[suffix[i]]++;
    }

    for(int i=tlen;i-1>=0;i--){
        suf_cnt[i-1]+=suf_cnt[i];
    }

    long long ans=0;
    for(int i=0;i<=tlen;i++){
        ans+=pre_cnt[i]*suf_cnt[tlen-i];
    }
    printf("%lld\n",ans);
    return 0;
}
/*
prefix[i] = the length of the longest prefix of Si that matches T
suffix[i] = the length of the longest suffix of Si that matches T
ex. S1="abde", T="abcde" => prefix[1]=2, suffix[1]=2

pre_cnt[i] = # of strings whose length of the longest prefix is i
first define suf_cnt[i] to be "# of strings whose length of the longest suffix = i" and do suffix sum,
then we have suf_cnt[i] = "# of strings whose length of the longest suffix >= i"

enumerate all possible prefix lengths from 0 to (T's len),
and find the # of strings whose longest suffix's length >= (T's len)-i
*/