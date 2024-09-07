#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int main(){
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.length();i++){  //start from beginning, change only when s[i]>t[i]
        if(s[i]>t[i]){
            s[i]=t[i];
            ans.emplace_back(s);
        }
    }
    for(int i=s.length()-1;i>=0;i--){   //start from the end, make s and t the same
        if(s[i]!=t[i]){
            s[i]=t[i];
            ans.emplace_back(s);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto s:ans){
        cout<<s<<'\n';
    }
    return 0;
}