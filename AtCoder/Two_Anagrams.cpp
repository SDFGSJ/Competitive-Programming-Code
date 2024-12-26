#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    if(s<t){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}
/*
make s/t lexicographically smallest/largest
if s<t after transition, ans is yes
*/