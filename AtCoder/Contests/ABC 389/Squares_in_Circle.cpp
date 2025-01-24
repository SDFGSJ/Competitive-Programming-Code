#include<bits/stdc++.h>
using namespace std;
double dx[4]={0.5,0.5,-0.5,-0.5}, dy[4]={0.5,-0.5,-0.5,0.5};
long long r;
double dist(double x1,double y1, double x2, double y2){
    double diffx=abs(x1-x2), diffy=abs(y1-y2);
    return diffx*diffx+diffy*diffy;
}
bool valid(int num,double y){
    double x=0.5+num;
    for(int i=0;i<4;i++){
        if(dist(0.5,0.5,x+dx[i],y+dy[i]) > r*r){
            return false;
        }
    }
    return true;
}
int main(){
    scanf("%lld",&r);
    long long ans=2*(r-1)+1;    //# of squares in the circle on y=0.5 line
    for(int i=1;i+0.5<r;i++){
        int L=0,R=1e6+1;
        while(L+1<R){
            int mid=L+(R-L)/2;
            if(valid(mid,i+0.5)){
                L=mid;
            }else{
                R=mid;
            }
        }
        ans+=2*(2*L+1);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
binary search
let (0.5, 0.5) be the origin
use a horizontal line scanning from y=1.5 to r
we count the # of squares whose centers are on the line y=1.5, 2.5, ... r
use binary search to find the last square s.t. dist(its center, origin) <= r
then the # of squares on the line y=i+0.5 is 2*L+1, same for y=-(i+0.5)
beware of r overflow and the left bound of binary search
*/