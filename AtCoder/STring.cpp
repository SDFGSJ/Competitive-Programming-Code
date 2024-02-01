#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int main(){
    string x;
    cin>>x;
    for(int i=0;i<x.length();i++){
        if(x[i]=='T' && !s.empty() && s.top()=='S'){
            s.pop();
        }else{
            s.emplace(x[i]);
        }
    }
    cout<<s.size()<<'\n';
    return 0;
}