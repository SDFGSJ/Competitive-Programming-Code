#include<bits/stdc++.h>
using namespace std;
bool valid(int num,int x){
    long long res=1ll*num*(num+1)/2;
    return x<=res;
}
int main(){
    int x;
    scanf("%d",&x);

    int L=0,R=1e5;
    while(L+1<R){
        int mid=L+(R-L)/2;
        if(valid(mid,x)){
            R=mid;
        }else{
            L=mid;
        }
    }
    printf("%d\n",R);
    return 0;
}
/*
bs
1 => 1

2 => 0+2
3 => 1+2

4 => 1+0+3
5 => 0+2+3
6 => 1+2+3

7 => 0+0+3+4
8 => 1+0+3+4
9 => 0+2+3+4
10 => 1+2+3+4

1,3,6,10,15...
find the 1st i s.t. 1+...+(i-1) < X <= 1+...+i
then i is the ans
*/