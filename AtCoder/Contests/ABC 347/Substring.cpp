#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        for(int j=1;j<=str.length()-i;j++){
            //cout<<str.substr(i,j)<<'\n';
            s.emplace(str.substr(i,j));
        }
    }
    printf("%d\n",s.size());
    return 0;
}