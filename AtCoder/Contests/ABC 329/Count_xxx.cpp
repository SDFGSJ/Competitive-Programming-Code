#include<bits/stdc++.h>
using namespace std;
char str[200010];
map<char,int> m;
int main(){
    int n;
    scanf("%d%s",&n,str);
    for(int i=0;i<n;){
        int j=i;
        while(str[j]==str[i]){
            j++;
        }
        int cnt=j-i;
        m[str[i]]=max(m[str[i]],cnt);
        i=j;
    }
    int ans=0;
    for(auto [k,v]:m){
        ans+=v;
    }
    printf("%d\n",ans);
    return 0;
}