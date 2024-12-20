#include<bits/stdc++.h>
using namespace std;
int cnt[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    int kind=0;
    for(int i=1;i<=100000;i++){
        if(cnt[i]>=1){
            kind++;
        }
    }

    if((n-kind)%2){
        printf("%d\n",kind-1);
    }else{
        printf("%d\n",n-kind);
    }
    return 0;
}