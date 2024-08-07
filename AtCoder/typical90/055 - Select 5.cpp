#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
    int n,p,q;
    scanf("%d%d%d",&n,&p,&q);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        a[i]%=p;
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int m=l+1;m<n;m++){
                        long long tmp1=(a[i] * a[j])%p;
                        tmp1=(tmp1*a[k])%p;
                        tmp1=(tmp1*a[l])%p;
                        tmp1=(tmp1*a[m])%p;
                        if(tmp1==q){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}