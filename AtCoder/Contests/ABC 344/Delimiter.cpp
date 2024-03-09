#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(){
    int num;
    while(1){
        scanf("%d",&num);
        s.push(num);
        if(num==0){
            break;
        }
    }
    while(!s.empty()){
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}