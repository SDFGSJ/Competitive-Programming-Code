#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> v;
    string s;
    cin>>s;

    sort(s.begin(),s.end());
    do{
        v.push_back(s);
    }while(next_permutation(s.begin(),s.end()));

    cout<<v.size()<<'\n';
    for(auto& s:v){
        cout<<s<<'\n';
    }
    return 0;
}