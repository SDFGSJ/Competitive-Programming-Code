#include<bits/stdc++.h>
using namespace std;
int idx[200010];    //idx[i]=the index of number i
int main(){
    int n,i,ans=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int num;    //num=1~n
        scanf("%d",&num);
        idx[num]=i;
    }

    for(i=2;i<=n;i++){
        if(idx[i-1]>idx[i]){    //decreasing => ans+1
            ans+=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}