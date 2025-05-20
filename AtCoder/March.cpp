#include<bits/stdc++.h>
using namespace std;
char s[15];
int cnt[26];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        if(s[0]!='M' && s[0]!='A' && s[0]!='R' && s[0]!='C' && s[0]!='H'){
            continue;
        }
        cnt[s[0]-'A']++;
    }

    long long ans=0;
    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){
            for(int k=j+1;k<26;k++){
                ans+=1ll*cnt[i]*cnt[j]*cnt[k];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
alphabet distribution + brute force
cnt[i] = # of people whose name starts with letter 'A'+i
*/