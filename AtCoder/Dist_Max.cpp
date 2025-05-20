#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+1;
int main(){
    int n;
    scanf("%d",&n);
    int bltr_m=INT_MAX,bltr_M=INT_MIN;  //bottom-left top-right
    int brtl_m=INT_MAX,brtl_M=INT_MIN;  //bottom-right top-left
    for(int i=0;i<n;i++){
        int x,y;    //point (x,y)
        scanf("%d%d",&x,&y);
        bltr_m=min(bltr_m,x+y); //dist((0,0), (x,y))
        bltr_M=max(bltr_M,x+y);

        brtl_m=min(brtl_m, abs(inf-x)+y);   //dist((inf,0), (x,y))
        brtl_M=max(brtl_M,abs(inf-x)+y);
    }
    printf("%d\n",max(bltr_M-bltr_m, brtl_M-brtl_m));
    return 0;
}
/*
make use of x,y's range
let (0,0) be point O, (1e9+1,0) be point P and dist(A,B) = dist between 2 points A(x1,y1), B(x2,y2) = |x1-x2|+|y1-y2|
suppose we have 2 points A(x1,y1), B(x2,y2), we have the following 2 cases:
(1)dist(A,O)<dist(B,O) and the direction of the line passing thru A,B is bottom-left <=> top-right
then dist(A,B) = |x1-x2|+|y1-y2| = |x2-x1|+|y2-y1| = x2-x1+y2-y1 = (x2+y2)-(x1+y1) = dist(B,O) - dist(A,O)
(2)dist(A,P)<dist(B,P) and ... bottom-right <=> top-left
view point P as pivot, we have similar induction process as (1)
*/