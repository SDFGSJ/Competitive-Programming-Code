#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
    int n,k;
    scanf("%d%d%s",&n,&k,s+1);

    int l=1,ans=1,cnt=0;
    for(int r=1;r<=n;r++){
        if(s[r]=='0' && s[r]!=s[r-1]){
            cnt++;
        }
        while(cnt>k){
            l++;
            if(s[l]=='1' && s[l-1]=='0'){
                cnt--;
            }
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}
/*
2 pointers
store string s using 1-indexed
cnt = # of consecutive '0's component in [l,r]
whenever the right pointer encounters '0' and the previous char is '_'(for idx=0) or '1', we increment cnt
if the left pointer encounters '1' and the previous char is '0', we decrement cnt
l,r = left/rightmost idx s.t. # of 0 compo in [l,r]<=k
*/