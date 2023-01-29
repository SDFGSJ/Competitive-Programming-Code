#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    int i;
    string str;
    for(i=0;i<4;i++){
        cin>>str;
        s.insert(str);
    }
    if(s.count("H") && s.count("2B") && s.count("3B") && s.count("HR")){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}