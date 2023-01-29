#include<bits/stdc++.h>
using namespace std;
int a[25];
int main(){
    int n,i,j;
    long long total=0,ans=1e16;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        total+=a[i];
    }

    for(i=0;i < (1<<n);i++){    //enumerate all subset
        long long sum=0;
        for(j=0;j<32;j++){
            if(i & (1<<j)){
                sum+=a[j];  //sum up all the elements in the subset
            }
        }
        //one has sum {sum},the other has sum {total-sum}
        ans = min(ans, abs((total-sum)-sum));
    }
    printf("%lld",ans);
    return 0;
}