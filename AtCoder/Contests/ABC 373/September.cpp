#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0;
    for(int i=1;i<=12;i++){
        string s;
        cin>>s;
        if(i==s.length()){
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}