#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
bool valid(double x, int n){
    return x*x*x+x>n;
}
int main(){
    int n;
    scanf("%d",&n);

    double l=0.0,r=100.0;
    while(abs(l-r)>eps){
        double mid=(l+r)/2.0;
        if(valid(mid,n)){
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%lf\n",r);
    return 0;
}