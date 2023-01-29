#include<bits/stdc++.h>
using namespace std;
int a[150010];
int prefix[150010]; //prefix sum
int main(){
    int i;
    int n,width,sum=0,idx=0;

    scanf("%d%d",&n,&width);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        prefix[idx]=sum,idx++;
    }

    int m=1e9,minidx=0;
    for(i=0;i<=idx-width;i++){
        if(i==0){
            if(prefix[i+width-1]<m){
                m=prefix[i+width-1];
                minidx=i;
            }
        }else{
            if(prefix[i+width-1]-prefix[i-1]<m){
                m=prefix[i+width-1]-prefix[i-1];
                minidx=i;
            }
        }
    }
    printf("%d\n",minidx+1);
    return 0;
}