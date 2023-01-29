#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    int n,num,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        s.insert(num);
    }
    if(s.size()==n){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}