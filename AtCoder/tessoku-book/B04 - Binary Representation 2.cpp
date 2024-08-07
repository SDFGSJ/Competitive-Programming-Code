#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int base=1,ans=0;
    for(int i=s.length()-1;i>=0;i--){
        ans+=(s[i]-'0')*base;
        base*=2;
    }
    printf("%d\n",ans);
    return 0;
}