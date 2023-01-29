#include<bits/stdc++.h>
using namespace std;
string num[10]={"","","2","3","223","5","53","7","7222","7332"};
char str[20];
int main(){
    int len,i;
    string ans;
    scanf("%d%s",&len,str);
    for(i=0;i<len;i++){
        ans+=num[str[i]-'0'];
    }
    sort(ans.begin(),ans.end(),greater<char>());
    cout<<ans<<"\n";
    return 0;
}