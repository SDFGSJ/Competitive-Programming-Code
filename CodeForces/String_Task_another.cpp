#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
    string s;
    cin>>s;
    for(i=0;s[i]!='\0';i++){
        s[i]=tolower(s[i]);
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='y'){
            cout<<'.'<<s[i];
        }
    }
    return 0;
}