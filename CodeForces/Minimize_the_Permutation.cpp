#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,start,min_idx;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        /*
        find the min element in range [a+start,a+n]
        right shift every elements in [a+start,a+min_idx]
        check if start==min_idx and update start
        */
        start=0,min_idx=-1;
        while(min_idx!=n-1){
            min_idx=min_element(a+start,a+n)-a;
            for(i=start;i<min_idx;i++){
                swap(a[i],a[min_idx]);
            }
            if(start==min_idx){
                start=min_idx+1;
            }else{
                start=min_idx;
            }
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}