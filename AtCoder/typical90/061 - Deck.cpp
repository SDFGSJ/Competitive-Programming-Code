#include<bits/stdc++.h>
using namespace std;
deque<int> de;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int t,x;
        scanf("%d%d",&t,&x);
        if(t==1){
            de.emplace_front(x);
        }else if(t==2){
            de.emplace_back(x);
        }else{
            printf("%d\n",de[x-1]);
        }
    }
    return 0;
}