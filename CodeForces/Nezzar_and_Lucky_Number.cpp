#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,d,num;
        scanf("%d%d",&n,&d);
        for(i=0;i<n;i++){
            bool yes=false;
            scanf("%d",&num);
            //if the number >= d*10,then it definitely can be written as the sum of lucky numbers
            if(num>=d*10){
                printf("yes\n");
                continue;
            }
            while(num>0){
                if(num%d==0){
                    yes=true;
                    break;
                }
                num-=10;
            }
            if(yes){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }
    return 0;
}