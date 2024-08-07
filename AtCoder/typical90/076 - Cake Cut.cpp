#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    if(sum%10!=0){  //sum must be multiple of 10
        printf("No\n");
        return 0;
    }

    for(int i=n;i<2*n;i++){ //repeat the elements to simulate cycle
        a[i]=a[i-n];
    }

    int l=0,r=0;
    long long total=a[0];
    while(l<2*n-1){
        if(total==sum/10){
            printf("Yes\n");
            return 0;
        }else if(total<sum/10){
            if(r+1<2*n){    //r haven't reached to the rightmost
                r++;
                total+=a[r];
            }
        }else{
            total-=a[l];
            if(l==r){   //move l,r together
                l++,r++;
                total+=a[l];
            }else{  //only move l, guarantee that l<r
                l++;
            }
        }
    }
    printf("No\n");
    return 0;
}
//two pointers