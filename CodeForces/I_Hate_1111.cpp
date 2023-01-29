#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,cnt11=0,cnt100=0;
        bool yes=false;
        scanf("%d",&n);
        while(n>0){
            if(n%11==0){
                cnt11=n/11;
                break;
            }
            n-=100;
            cnt100++;
        }
        //have to notice the count of 11 and 100,else will get WA
        if(cnt11>=cnt100){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}