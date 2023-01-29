#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int s,mul=1;
        scanf("%d",&s);
        while(mul*mul<s){
            mul++;
        }
        printf("%d\n",mul);
    }
    return 0;
}