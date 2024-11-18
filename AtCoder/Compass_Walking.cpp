#include<bits/stdc++.h>
using namespace std;
long long r,x,y;
bool valid(long long mid){
    return mid*mid >= (x*x+y*y+r*r-1)/(r*r);
}
int main(){
    scanf("%lld%lld%lld",&r,&x,&y);
    long long L=0,R=2e5+1;
    while(L+1<R){
        long long mid=L+(R-L)/2;
        if(valid(mid)){
            R=mid;
        }else{
            L=mid;
        }
    }
    if(r*r>x*x+y*y){
        R=2;
    }
    printf("%lld\n",R);
    return 0;
}
/*
the possible coordinate after 1st move is a circle centered at (0,0) with r=R
the possible coordinate after 2nd move is a circle centered at (0,0) with r=2R
...

so it reamins to find i s.t. (X,Y) is between circle with r=iR and circle with r=(i+1)R (if R*R<=x*x+y*y)
otherwise the ans is always 2 if R*R>x*x+y*y
use bs to avoid floating point
R*mid >= sqrt(x*x+y*y)
=> R*R*mid*mid >= x*x+y*y
=> mid*mid >= ceiling((x*x+y*y) / (R*R))
=> find the first mid s.t. mid*mid >= floor((x*x+y*y + R*R-1) / (R*R))

other sol:
let dist=sqrt(x*x+y*y)
ceil(dist/r) if r<=dist
2 if r>dist
*/