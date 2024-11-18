#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,s;
        scanf("%lld%lld",&a,&s);
        if(s>=2*a && ((s-2*a)&a)==0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
/*
i-th bit of a is 1 <=> i-th bit of both x,y are 1, so we have s>=2a
the other bits must be 0, else we wont have x&y=a
=> yes if (s-2a)&a is 0
*/