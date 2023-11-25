#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        s.emplace(num);
    }
    s.erase(*s.rbegin());
    printf("%d\n",*s.rbegin());
    return 0;
}