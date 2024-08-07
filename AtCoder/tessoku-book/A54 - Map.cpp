#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        int op;string x;
        cin>>op>>x;
        if(op==1){
            int y;
            cin>>y;
            m[x]=y;
        }else{
            cout<<m[x]<<'\n';
        }
    }
    return 0;
}