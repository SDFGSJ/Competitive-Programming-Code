#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,neg=0,minabs=INT_MAX;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        minabs=min(minabs,abs(a[i]));
        if(a[i]<0){
            neg++;
            a[i]*=-1;
        }
        sum+=a[i];
    }

    if(neg%2){
        sum-=2*minabs;
    }
    printf("%lld\n",sum);
    return 0;
}
/*
the ans depends on the parity of the # of negative numbers
if there are odd/even neg num, there will be 1/0 neg num after all operations
in order to maximize the sum, let the number with the smallest abs value to be the only neg num
so the ans is
sum(a[i]) if even neg num
sum(a[i])-2*minabs if odd neg num
*/