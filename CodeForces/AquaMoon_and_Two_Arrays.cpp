#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
/*
few[i]=the idx where a[i]<b[i]
more[i]=the idx where a[i]>b[i]
*/
int few[105],more[105];
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        bool no=false;
        int fewidx=0,moreidx=0,asum=0,bsum=0,step=0;
        for(i=0;i<105;i++){
            few[i]=more[i]=0;
        }

        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            asum+=a[i];
        }
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
            bsum+=b[i];
        }

        if(asum!=bsum){
            printf("-1\n");
            continue;
        }
        for(i=0;i<n;i++){
            step+=abs(a[i]-b[i]);
            if(a[i]<b[i]){
                few[fewidx++]=i;
            }else if(a[i]>b[i]){
                more[moreidx++]=i;
            }
        }

        step/=2;
        printf("%d\n",step);
        i=j=0;  //few[i],more[j]
        while(a[ few[i] ] != b[ few[i] ]){
            printf("%d %d\n",more[j]+1,few[i]+1);  //move 1 from more to less
            a[ few[i] ]++;
            a[ more[j] ]--;
            if(a[ few[i] ] == b[ few[i] ]){
                i++;
            }
            if(a[ more[j] ] == b[ more[j] ]){
                j++;
            }
        }
    }
    return 0;
}