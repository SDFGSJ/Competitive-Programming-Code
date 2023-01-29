#include<bits/stdc++.h>
using namespace std;
const double pi = std::acos(-1);
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        n*=2;   //2n
        double theta = 2*pi/n;
        printf("%lf\n",sin(theta)/(1.0-cos(theta)));
    }
    return 0;
}