#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="atcoder";
    int l,r;
    cin>>l>>r;
    l--,r--;
    cout<<s.substr(l,r-l+1)<<"\n";
    return 0;
}