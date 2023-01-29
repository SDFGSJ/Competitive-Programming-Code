#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,l,i;
    cin>>n>>l;
    for(i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());

    string ans="";
    for(auto s:v){
        ans+=s;
    }
    cout<<ans<<'\n';
    return 0;
}