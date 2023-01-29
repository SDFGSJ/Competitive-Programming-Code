#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        string s;
        cin>>s;
        if(m.count(s)!=0){
            cout<<s<<m[s]<<'\n';
            m[s]++;
        }else{
            cout<<"OK\n";
            m[s]=1;
        }
    }
    return 0;
}