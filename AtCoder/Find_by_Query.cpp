#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    int L=1,R=n;
    while(L+1<R){
        int mid=L+(R-L)/2;
        printf("? %d\n",mid);
        fflush(stdout);

        int res;
        scanf("%d",&res);
        if(res){
            R=mid;
        }else{
            L=mid;
        }
    }
    printf("! %d\n",L);
    fflush(stdout);
    return 0;
}
/*
bs
understood after reading editorial
since S[1]=0 and S[N]=1, there must be an idx i s.t. S[i] != S[i+1]
use bs to find the boundary of 0,1
*/