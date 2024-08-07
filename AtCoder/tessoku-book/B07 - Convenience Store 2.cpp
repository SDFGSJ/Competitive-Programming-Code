#include<bits/stdc++.h>
using namespace std;
int answer[500010],delta[500010];
int main(){
    int t,n;
    scanf("%d%d",&t,&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        delta[l]++,delta[r]--;
    }

    answer[0]=delta[0];
    for(int i=1;i<=t;i++){
        answer[i]=answer[i-1]+delta[i];
    }
    for(int i=0;i<=t-1;i++){
        printf("%d\n",answer[i]);
    }
    return 0;
}