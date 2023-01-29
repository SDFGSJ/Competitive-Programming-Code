#include<bits/stdc++.h>
using namespace std;
int cnt[15];
int main(){
    int a,i;
    for(i=0;i<5;i++){
        scanf("%d",&a);
        cnt[a]++;
    }
    bool has2=false,has3=false;
    for(i=1;i<=13;i++){
        if(cnt[i]==2){
            has2=true;
        }else if(cnt[i]==3){
            has3=true;
        }
    }
    if(has2 && has3){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}