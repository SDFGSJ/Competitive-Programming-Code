#include<bits/stdc++.h>
using namespace std;
int J[55],G[55];
int main(){
    int t,n,m,k,i;
    scanf("%d",&t);
    while(t--){
        long long jsum=0,gsum=0;
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++){
            scanf("%d",&J[i]);
            jsum+=J[i];
        }
        for(i=0;i<m;i++){
            scanf("%d",&G[i]);
            gsum+=G[i];
        }

        int jmin=*min_element(J,J+n);
        int jmax=*max_element(J,J+n);
        int gmin=*min_element(G,G+m);
        int gmax=*max_element(G,G+m);

        long long joddbest=0,jevenbest=0;
        if(jmin<gmax){
            swap(J[min_element(J,J+n)-J], G[max_element(G,G+m)-G]);
            jsum=jsum-jmin+gmax;
            gsum=gsum+jmin-gmax;
            joddbest=jsum;
        }else{  //no-op
            joddbest=jsum;
        }
        
        jsum=jsum - *max_element(J,J+n) + *min_element(G,G+m);
        gsum=gsum - *min_element(G,G+m) + *max_element(J,J+n);
        swap(J[max_element(J,J+n)-J], G[min_element(G,G+m)-G]);
        jevenbest=jsum;

        if(k%2){
            printf("%lld\n",joddbest);
        }else{
            printf("%lld\n",jevenbest);
        }
    }
    return 0;
}