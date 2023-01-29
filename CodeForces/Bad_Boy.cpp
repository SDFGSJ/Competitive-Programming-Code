#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n,m,i,j;
        scanf("%lld%lld%lld%lld",&n,&m,&i,&j);
        long long x1,x2,y1,y2;

        if(abs(i-1)>abs(i-n)){  //if the distance from i to 1 is longer than to n
            x1=1;
        }else{
            x1=n;
        }
        if(abs(j-1)>abs(j-m)){  //if the distance from j to 1 is longer than to n
            y1=1;
        }else{
            y1=m;
        }

        if(x1==n){  //choose point2 position based on point1's position
            x2=1;
        }else{
            x2=n;
        }
        if(y1==m){
            y2=1;
        }else{
            y2=m;
        }

        printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
    }
    return 0;
}