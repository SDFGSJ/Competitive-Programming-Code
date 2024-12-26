#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int n,m;
bool valid(int price){
    int seller_cnt=upper_bound(a,a+n,price)-a;
    int buyer_cnt=(b+m)-lower_bound(b,b+m,price);
    return seller_cnt>=buyer_cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);

    int L=-1,R=1e9+1;
    while(L+1<R){
        int mid=L+(R-L)/2;
        if(valid(mid)){
            R=mid;
        }else{
            L=mid;
        }
    }
    printf("%d\n",R);
    return 0;
}
/*
bs + lower/upper bound
sort a[],b[] asc
*/