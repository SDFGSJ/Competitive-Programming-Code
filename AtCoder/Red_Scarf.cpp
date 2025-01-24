#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n;
    scanf("%d",&n);
    int xor_total=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        xor_total^=a[i];
    }

    for(int i=0;i<n;i++){
        printf("%d ",xor_total^a[i]);
    }
    printf("\n");
    return 0;
}
/*
since n is even, a[i] is xored odd # of times
so the xor sum of all a[i]'s = a[1]^...^a[n]
and use this number to xor each a[i] to get cat i's number
*/