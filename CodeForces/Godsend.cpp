#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    bool hasodd=false;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num%2==1){
            hasodd=true;
        }
    }
    //if there is at least one odd,then first player wins
    if(hasodd){
        printf("First\n");
    }else{
        printf("Second\n");
    }
    return 0;
}