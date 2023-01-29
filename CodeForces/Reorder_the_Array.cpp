#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,i,l,r,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);

    l=0;
    //find the first idx that is bigger than a[0]
    for(i=0;i<n;i++){
        if(a[i]>a[0]){
            r=i;
            break;
        }
    }

    //repeat until r is out of boundary
    while(r<n){
        if(a[l]<a[r]){
            cnt++,l++;
        }
        r++;
    }
    printf("%d\n",cnt);
    return 0;
}