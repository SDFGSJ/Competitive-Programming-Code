#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);

    double pi=acos(-1),rad=d*pi/180.0;
    double newa=a*cos(rad)-b*sin(rad);
    double newb=a*sin(rad)+b*cos(rad);
    printf("%lf %lf",newa,newb);
    return 0;
}