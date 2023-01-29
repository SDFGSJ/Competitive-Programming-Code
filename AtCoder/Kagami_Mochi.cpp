#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        s.insert(num);
    }
    printf("%d\n",s.size());
    return 0;
}