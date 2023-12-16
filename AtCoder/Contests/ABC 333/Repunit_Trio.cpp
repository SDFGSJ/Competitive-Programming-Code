#include<bits/stdc++.h>
using namespace std;
set<long long> s;
vector<long long> v;
vector<long long> ones;
int main(){
    long long num=1ll;
    while(ones.size()<15){
        ones.emplace_back(num);
        num=num*10+1;
    }

    int n;
    scanf("%d",&n);
    for(int i=0;i<ones.size();i++){
        for(int j=0;j<ones.size();j++){
            for(int k=0;k<ones.size();k++){
                s.emplace(ones[i]+ones[j]+ones[k]);
            }
        }
    }
    for(auto num:s){
        v.emplace_back(num);
    }
    printf("%lld\n",v[n-1]);
    return 0;
}