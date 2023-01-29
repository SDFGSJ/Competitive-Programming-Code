#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,ans=0;
    scanf("%d",&n);
    x=n/2;
    if(n%2==1){
        ans=2*(x+1)*(x+2);
    }else{
        ans=(x+1)*(x+1);
    }
    printf("%d\n",ans);
    return 0;
}
/*
LR=abs(horizontal displacement)
UD=abs(vertical displacement)
n=8:
(LR)(UD)
4   4   8/2=4
2   2
0   0

total=
4 combination * 2 numbers(2,4) * 2 numbers(2,4) +
2 combination * 1 number(LR:0) * 2 number(UD:2,4) +
2 combination * 2 number(UD:2,4) * 1 number(LR:0)  + 1(0,0 pair)
formula=
4(n/2)(n/2)+2( 1*(n/2) + (n/2)*1 )+1 = n*n+2*n+1 = (n+1)(n+1)

n=7:
(LR)(UD)
4   3
2   1
0   

total=
2 kind([LR(4,2),UD(3,1)] or [UD(4,2),LR(3,1)]) * 4 combination * 2 numbers(2,4) * 2 numbers(3,1) +
2 kind * (1 number(LR:0) * 2 numbers(UD:3,1) + 1 number(UD:0) * 2 numbers(LR:3,1))
formula=
2m+1=odd    ex.2m+1==7
m=odd =>2*4( (m+1)/2 )( (m+1)/2 )+2[ ( (m+1)/2 * 1 + 1 * (m+1)/2 )
        2(m+1)^2+2(m+1)=2(m+1)(m+2)

m=even=>2*4(m/2)( (m+2)/2 )+2[ ( (m+2)/2 * 1 + 1 * (m+2)/2 )
        2m(m+2)+2(m+2)=2(m+1)(m+2)
*/