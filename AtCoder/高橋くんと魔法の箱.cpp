#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        while(num%2==0){
            num/=2;
        }
        s.emplace(num);
    }
    printf("%ld\n",s.size());
    return 0;
}
/*
the output of x, 2x, 4x, ...(2^i)x are all the same
num /= 2 until it can't be divided by 2
let this result be the output of a num then store it in a set
*/