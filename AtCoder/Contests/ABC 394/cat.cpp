#include<bits/stdc++.h>
using namespace std;
vector<pair<int,string>> vec;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vec.emplace_back(s.length(),s);
    }

    sort(vec.begin(),vec.end());
    string ans="";
    for(auto [len,str]:vec){
        ans+=str;
    }
    cout<<ans<<'\n';
    return 0;
}