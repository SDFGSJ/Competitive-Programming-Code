#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    cin>>t;
    while(t--){
        int len;
        string s;
        cin>>len>>s;

        queue<string> q;
        for(i=0;i<26;i++){
            q.push(string(1,'a'+i));
        }
        while(!q.empty()){
            string a=q.front();
            q.pop();
            if(s.find(a)==string::npos){
                cout<<a<<'\n';
                break;
            }
            for(i=0;i<26;i++){
                a.push_back('a'+i);
                q.push(a);
                a.pop_back();
            }
        }
    }
    return 0;
}