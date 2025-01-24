#include<bits/stdc++.h>
using namespace std;
int distri[20];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            distri[s[j]-'a'] |= (1<<i);
        }
    }

    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        int cnt=0;
        for(int i=0;i<26;i++){
            int str_cnt=__builtin_popcount(bit&distri[i]);  //# of str that contains alphabet 'a'+i
            if(str_cnt==k){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}
/*
bit enumerate
distri[i] = list of string idx j that character 'a'+i appears at, use 32-bit integer to store the information
for each bitmask, check every 26 alphabets and take max
*/