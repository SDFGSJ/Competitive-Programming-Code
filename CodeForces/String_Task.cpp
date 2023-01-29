#include<bits/stdc++.h>
using namespace std;
bool have_to_erase(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y'){
        return true;
    }
    return false;
}
int main(){
    int i;
    string s;
    cin>>s;
    for(i=0;s[i]!='\0';){
        s[i]=tolower(s[i]);
        if(have_to_erase(s[i])){
            s=s.erase(i,1);
        }else{
            i++;
        }
    }
    for(auto c:s){
        cout<<"."<<c;
    }
    cout<<'\n';
    return 0;
}