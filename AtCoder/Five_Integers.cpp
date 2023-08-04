#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    int i,num;
    for(i=0;i<5;i++){
        scanf("%d",&num);
        s.insert(num);
    }
    printf("%d",s.size());
    return 0;
}