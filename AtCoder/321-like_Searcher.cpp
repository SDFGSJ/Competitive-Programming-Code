#include<bits/stdc++.h>
using namespace std;
set<long long> s;
int main(){
    int k;
    scanf("%d",&k);

    queue<long long> q;
    for(int i=1;i<=9;i++){
        q.emplace(i);
    }
    while(!q.empty()){
        long long num=q.front();q.pop();
        s.emplace(num);

        for(int i=0;i<num%10;i++){
            q.emplace(num*10 + i);
        }
    }

    vector<long long> v(s.begin(), s.end());
    printf("%lld\n",v[k-1]);
    return 0;
}