#include<bits/stdc++.h>
using namespace std;
char s[200010];
vector<char> v;
int main(){
    int n;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++){
        v.emplace_back(s[i]);
        int sz=v.size();
        if(sz>=3 && v[sz-3]=='f' && v[sz-2]=='o' && v[sz-1]=='x'){
            v.pop_back();v.pop_back();v.pop_back();
        }
    }
    printf("%d\n",v.size());
    return 0;
}