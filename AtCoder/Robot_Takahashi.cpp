#include<bits/stdc++.h>
using namespace std;
char s[200010];
int w[200010];
int f(int num,int n){
    int res=0;
    for(int i=0;i<n;i++){
        if(w[i]<num && s[i]=='0'){
            res++;
        }
        if(w[i]>=num && s[i]=='1'){
            res++;
        }
    }
    return res;
}
int main(){
    int n,m=INT_MAX,M=INT_MIN;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        m=min(m,w[i]);M=max(M,w[i]);
    }

    int L=m,R=M+1;
    while(L+2<R){
        int mid1=L+(R-L)/3, mid2=R-(R-L)/3;
        int mid1_res=f(mid1,n), mid2_res=f(mid2,n);
        //printf("f(%d)=%d, f(%d)=%d\n",mid1,mid1_res,mid2,mid2_res);
        if(mid1_res>mid2_res){
            R=mid2;
        }else{
            L=mid1;
        }
    }
    //printf("L=%d, R=%d\n",L,R);
    printf("%d\n",max({f(L,n), f(L+1,n), f(R,n)}));
    return 0;
}
/*
ternary search find max f(X)
*/