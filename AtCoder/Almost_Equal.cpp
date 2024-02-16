#include<bits/stdc++.h>
using namespace std;
int diff(string a,string b,int m){
    int cnt=0;
    for(int i=0;i<m;i++){
        cnt+=(a[i]!=b[i]);
    }
    return cnt;
}
bool valid(int n, int m, string s[]){
    bool ok=true;
    for(int i=0;i<n;i++){
        if(diff(s[i],s[i+1],m)!=1){
            ok=false;
        }
    }
    return ok;
}
int main(){
    string s[10];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    do{
        if(valid(n,m,s)){
            cout<<"Yes\n";
            return 0;
        }
    }while(next_permutation(s,s+n));
    cout<<"No\n";
    return 0;
}