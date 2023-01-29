#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int len,cnt=0,i;
    string a,b;

    cin>>len;
    int tmp;
    for(i=0;i<len;i++){
        cin>>tmp;
        a.push_back('0'+tmp);
    }
    for(i=0;i<len;i++){
        cin>>tmp;
        b.push_back('0'+tmp);
    }

    //a is always lexicographically smaller
    if(a>b){
        swap(a,b);
    }
    while(a!=b){
        next_permutation(a.begin(),a.end());
        cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}