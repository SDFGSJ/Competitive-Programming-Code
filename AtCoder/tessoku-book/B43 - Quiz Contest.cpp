#include<bits/stdc++.h>
using namespace std;
int cnt[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    for(int i=1;i<=n;i++){
        printf("%d\n",m-cnt[i]);
    }
    return 0;
}