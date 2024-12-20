#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,k;
bool valid(int len){
    long long res=0;
    for(int i=0;i<n;i++){
        if(a[i]>len){   //no need to cut when a[i] <= len
            res+=a[i]/len;
        }
    }
    return res<=k;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int L=0,R=1e9;
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
binary search
find the 1st length l s.t. (# of cut to have longest len = l) <= k
if we meet a log whose length <= l, there's no need to cut it
only cut those logs whose length > l
*/