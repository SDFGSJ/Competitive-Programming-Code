#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s=="ABC"){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}