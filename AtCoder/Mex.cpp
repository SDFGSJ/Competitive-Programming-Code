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
    for(i=0;i<=2000;i++){
        if(s.count(i)==0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}