#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(min(a,b)>max(c,d) || min(c,d)>max(a,b)){ //if the biggest and the second biggest is in the same group
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    return 0;
}