#include<bits/stdc++.h>
using namespace std;
//no need to build an array
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int n,m,a,b,sum=0,maxa=-1e9,maxb=-1e9;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a);
            sum+=a;
            if(maxa<sum){
                maxa=sum;
            }
        }
        sum=0;
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&b);
            sum+=b;
            if(maxb<sum){
                maxb=sum;
            }
        }
        /*
        no need to spend O(n^2) to loop through a[] and b[] to find max a[i]+b[j]
        because max a[i]+b[j] is max(a[i])+max(b[j]),only takes O(1)
        */
        printf("%d\n",max(0,maxa)+max(0,maxb));
    }
    return 0;
}