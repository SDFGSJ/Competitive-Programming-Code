#include<bits/stdc++.h>
using namespace std;
long long a[200010];
vector<long long> v;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        v.emplace_back(a[i]);
        while(v.size()>=2 && v[v.size()-1]==v[v.size()-2]){
            int tmp=v[v.size()-1]+1;
            v.pop_back();v.pop_back();
            v.emplace_back(tmp);
        }
    }
    printf("%d\n",v.size());
    return 0;
}