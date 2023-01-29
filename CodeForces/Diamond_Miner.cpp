#include<bits/stdc++.h>
using namespace std;
long long x[100010],y[100010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,xidx=0,yidx=0;
        long long a,b;
        double ans=0.0;

        scanf("%d",&n);
        for(i=0;i<2*n;i++){
            scanf("%lld%lld",&a,&b);
            if(a==0){   //y-axis
                y[yidx]=abs(b);
                yidx++;
            }else{  //x-axis
                x[xidx]=abs(a);
                xidx++;
            }
        }
        sort(x,x+n);
        sort(y,y+n);
        for(i=0;i<n;i++){
            ans+=sqrt(x[i]*x[i]+y[i]*y[i]);
        }
        printf("%.15f\n",ans);
    }
    return 0;
}