#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i+2<s.length();i++){
        if(s[i]!=s[i+1] && s[i+1]==s[i+2]){
            cout<<i+1<<'\n';
            break;
        }else if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]==s[i+2]){
            cout<<i+2<<'\n';
            break;
        }else if(s[i]==s[i+1] && s[i+1]!=s[i+2]){
            cout<<i+3<<'\n';
            break;
        }
    }
    return 0;
}