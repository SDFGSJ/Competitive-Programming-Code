#include<bits/stdc++.h>
using namespace std;
long long a[46],b[46],c[46];  //a[i] = #elements in array a that mod 46 = i
int main(){
    int n,num;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        a[num%46]++;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        b[num%46]++;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        c[num%46]++;
    }

    long long ans=0;
    for(int i=0;i<46;i++){
        for(int j=0;j<46;j++){
            for(int k=0;k<46;k++){
                if((i+j+k)%46==0){
                    ans+=a[i]*b[j]*c[k];
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}