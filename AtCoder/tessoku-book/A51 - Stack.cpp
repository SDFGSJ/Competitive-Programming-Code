#include<bits/stdc++.h>
using namespace std;
stack<string> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            string x;
            cin>>x;
            s.push(x);
        }else if(op==2){
            cout<<s.top()<<'\n';
        }else{
            s.pop();
        }
    }
    return 0;
}