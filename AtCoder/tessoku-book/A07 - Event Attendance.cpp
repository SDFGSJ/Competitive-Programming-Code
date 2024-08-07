#include<bits/stdc++.h>
using namespace std;
int in[100010],out[100010];
int main(){
    int d,n;
    scanf("%d%d",&d,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&in[i],&out[i]);
    }
    sort(in,in+n);
    sort(out,out+n);
    int people=0;
    for(int i=1;i<=d;i++){
        int cnt=upper_bound(in,in+n,i)-lower_bound(in,in+n,i);
        people+=cnt;
        printf("%d\n",people);
        cnt=upper_bound(out,out+n,i)-lower_bound(out,out+n,i);
        people-=cnt;
    }
    return 0;
}