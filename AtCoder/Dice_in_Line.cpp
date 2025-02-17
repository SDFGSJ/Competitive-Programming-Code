#include<bits/stdc++.h>
using namespace std;
int p[200010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    double M=0,cur=0;
    for(int r=0,l=0;r<n;r++){
        cur+=(p[r]+1)/2.0;
        while(r-l+1>k){ //more than k dices in [l,r]
            cur-=(p[l]+1)/2.0;
            l++;
        }
        M=max(M,cur);
    }
    printf("%.10f\n",M);
    return 0;
}
/*
sliding window
E[a] = 1กั(1/a)+...+nกั(1/a) = a(a+1)/2/a = (a+1)/2
*/