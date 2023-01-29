#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //kadane's algorithm
    long long mymax = -1e9-1, sum=0;    //mymax should be negative,the first num in array might<0
    for(i=0;i<n;i++){
        if(sum+a[i]>a[i]){  //if adding a[i] makes sum bigger,then we pick a[i]
            sum+=a[i];
        }else{  //else we start a new sum with a[i]
            sum=a[i];
        }

        mymax=max(mymax,sum);
    }

    printf("%lld\n",mymax);
    return 0;
}