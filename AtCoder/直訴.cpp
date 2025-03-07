#include<bits/stdc++.h>
using namespace std;
int main(){
    int xa,ya,xb,yb,xc,yc;
    scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
    xb-=xa,xc-=xa;
    yb-=ya,yc-=ya;
    xa=ya=0;
    printf("%.6f\n",abs(xb*yc-yb*xc)/2.0);
    return 0;
}
/*
shift point a to the origin, then use the formula
*/