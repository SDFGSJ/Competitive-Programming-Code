#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        if(s.find(str)==s.end()){
            s.emplace(str);
            printf("%d\n",i);
        }
    }
    return 0;
}