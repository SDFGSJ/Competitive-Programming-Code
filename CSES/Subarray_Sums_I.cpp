#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n,target,i;
    int sum,count,l,r;
    scanf("%d%d",&n,&target);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    //two pointers, [l,r)
    sum=a[0],count=l=0,r=1;
    while(l<n && r<=n){
        if(sum<target){
            sum+=a[r];
            r++;
        }else if(sum>target){
            sum-=a[l];
            l++;
        }else{
            count++;
            sum=sum-a[l]+a[r];
            l++,r++;
        }
    }
    printf("%d\n",count);
    return 0;
}