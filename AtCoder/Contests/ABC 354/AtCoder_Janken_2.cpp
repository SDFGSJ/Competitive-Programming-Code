#include<bits/stdc++.h>
using namespace std;
vector<pair<string,int>> v;
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        string s;
        int c;
        cin>>s>>c;
        sum+=c;
        v.emplace_back(s,c);
    }
    sort(v.begin(),v.end());
    cout<<v[sum%n].first<<'\n';
    return 0;
}