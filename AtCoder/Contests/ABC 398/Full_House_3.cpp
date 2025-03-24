#include<bits/stdc++.h>
using namespace std;
int cnt[15];
int main(){
    for(int i=0;i<7;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    int three=0,two=0;
    for(int i=1;i<=13;i++){
        if(cnt[i]>=3){
            three++;
        }else if(cnt[i]==2){
            two++;
        }
    }
    if(three>=2 || (three==1 && two>=1)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}