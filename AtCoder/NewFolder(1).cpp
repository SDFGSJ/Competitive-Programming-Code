#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    string s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s;
        if(m.count(s)){
            cout<<s<<"("<<m[s]<<")\n";
        }else{
            cout<<s<<'\n';
        }
        m[s]++;
    }
    return 0;
}