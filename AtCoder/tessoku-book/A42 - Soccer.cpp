#include<bits/stdc++.h>
using namespace std;
int A[305],B[305];
int n,k;
int calc(int a,int b){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a<=A[i] && A[i]<=a+k && b<=B[i] && B[i]<=b+k){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&A[i],&B[i]);
    }

    int ans=-1;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            ans=max(ans,calc(i,j));
        }
    }
    printf("%d\n",ans);
    return 0;
}
//enumerate all possible values