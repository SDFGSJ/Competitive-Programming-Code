#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n;
bool valid(int b,int dist,int k){
    int cnt=upper_bound(a,a+n,b+dist)-lower_bound(a,a+n,b-dist);    //# of points in [b-dist, b+dist]
    return cnt>=k;
}
int main(){
    int q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    while(q--){
        int b,k;
        scanf("%d%d",&b,&k);
        int L=-1, R=2e8;
        while(L+1<R){
            int mid=L+(R-L)/2;
            if(valid(b,mid,k)){
                R=mid;
            }else{
                L=mid;
            }
        }
        printf("%d\n",R);
    }
    return 0;
}
/*
to find the k-th nearest, we can start from X = 0 to 2e8
find the first number dist s.t. # of points in [b-dist, b+dist] >= k
then dist would be the ans
*/