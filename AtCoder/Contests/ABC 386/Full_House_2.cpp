#include<bits/stdc++.h>
using namespace std;
int cnt[15];
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    cnt[a]++,cnt[b]++,cnt[c]++,cnt[d]++;
    int kind=0;
    for(int i=1;i<=13;i++){
        if(cnt[i]>0){
            kind++;
        }
    }
    if(kind==2){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}