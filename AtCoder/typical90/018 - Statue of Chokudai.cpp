#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int main(){
    long long t,l,X,Y;
    scanf("%lld%lld%lld%lld",&t,&l,&X,&Y);
    double theta=2*pi/t;    //ferris wheel rotate 2£k/t per second

    int q;
    scanf("%d",&q);
    while(q--){
        int e;
        scanf("%d",&e);
        long double y=-l/2.0*sin(e*theta);  //ferris wheel's y coor
        long double z=l/2.0*(1-cos(e*theta));   //ferris wheel's z coor
        long double a=sqrt(X*X + (Y-y)*(Y-y) + z*z);    //dist of ferris wheel coor and statue
        long double b=sqrt(z*z);    //dist of ferris wheel and ground(0,y,0)
        long double ans=asin(b/a);
        printf("%.12Lf\n",ans/pi*180);
    }
    return 0;
}