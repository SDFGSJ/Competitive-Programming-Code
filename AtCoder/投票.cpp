#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> um;   //<name,cnt>
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        um[name]++;
    }

    int M=0;
    string leader;
    for(auto [name,cnt]:um){
        if(cnt>M){
            leader=name;
            M=cnt;
        }
    }
    cout<<leader<<'\n';
    return 0;
}
/*
unordered map
*/