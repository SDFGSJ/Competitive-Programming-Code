#include<bits/stdc++.h>
using namespace std;
char str[200010];
int main(){
    int n;
    scanf("%d%s",&n,str);
    int wcnt=0,rcnt=0,swapcnt=0;
    for(int i=0;i<n;i++){
        if(str[i]=='W'){
            wcnt++;
        }else{
            rcnt++;
        }
    }
    for(int i=0;i<rcnt;i++){
        if(str[i]!='R'){
            swapcnt++;
        }
    }
    printf("%d\n",min({wcnt,rcnt,swapcnt}));
    return 0;
}
/*
3 ways to achieve
1. change all R to W (W...W)
2. change all W to R (R...R)
3. swap R to the front (R...RW...W)
*/