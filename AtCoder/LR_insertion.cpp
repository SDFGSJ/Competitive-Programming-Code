#include<bits/stdc++.h>
using namespace std;
char s[500010];
deque<int> dq;
int main(){
    int n;
    scanf("%d%s",&n,s+1);

    dq.emplace_back(n);
    for(int i=n;i>=1;i--){
        if(s[i]=='L'){  //i, (i-1)
            dq.emplace_back(i-1);
        }else{  //(i-1), i
            dq.emplace_front(i-1);
        }
    }

    for(auto num:dq){
        printf("%d ",num);
    }
    printf("\n");
    return 0;
}
/*
deque
do in reverse, iterate s from the back
if s[i] is L/R, then i is on the left/right of i-1
which means that i-1 is on the right/left of i
*/