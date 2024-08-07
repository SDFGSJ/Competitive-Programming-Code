#include<bits/stdc++.h>
using namespace std;
queue<string> que;
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
            que.push(x);
        }else if(op==2){
            cout<<que.front()<<'\n';
        }else{
            que.pop();
        }
    }
    return 0;
}