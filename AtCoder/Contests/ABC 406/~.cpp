#include<bits/stdc++.h>
using namespace std;
int p[300010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }

    long long ans=0;
    for(int l=2,r=2;r<=n-1;){   //we want to find a contiguous subarray s.t. arr[l..r] is strictly decreasing
        while(l+1<=n && p[l]<p[l+1]){   //move l to the peak
            l++;
        }
        r=l;    //r starts from l
        while(r+1<=n && p[r]>p[r+1]){   //move r to bottom
            r++;
        }
        int lbound=l;   //since l is peak, we need to find the nearest bottom on the left side, and let the idx of the nearest left bottom be lbound
        while(lbound-1>=1 && p[lbound]>p[lbound-1]){
            lbound--;
        }
        int rbound=r;   //since r is bottom, we need to find the nearest peak on the right side, and let the idx of the nearest right peak be rbound
        while(rbound+1<=n && p[rbound]<p[rbound+1]){
            rbound++;
        }

        ans+=1ll*(l-lbound)*(rbound-r); //(l-lbound),(rbound-r) = # of points that we can extend without affecting the "~" shape
        l=rbound;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
2 pointers
the key point is to find a strictly decreasing contiguous subarray s.t. arr[l] / arr[r] is the max / min element
*/