#include<bits/stdc++.h>
using namespace std;
int a[100010];
set<int> s;
map<int,int> m; //<value,rank>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        s.emplace(a[i]);
    }

    int rank=0;
    for(auto num:s){
        m[num]=rank;
        rank++;
    }

    for(int i=0;i<n;i++){
        printf("%d\n",m[a[i]]);
    }
    return 0;
}