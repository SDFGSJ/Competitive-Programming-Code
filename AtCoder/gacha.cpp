#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,i;
    string str;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str;
        s.insert(str);
    }
    cout<<s.size();
    return 0;
}