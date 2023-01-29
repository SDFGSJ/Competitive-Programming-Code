#include<bits/stdc++.h>
using namespace std;
int a[2010];
bool cmp(int a,int b){  //put even number at the front,odd at the last
    return a%2 < b%2;
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int n,cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        /*for(i=0;i<n;i++){
            printf("%d,",a[i]);
        }
        printf("\n");*/
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(__gcd(a[i],2*a[j])>1){
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}