#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int gcd=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        gcd=__gcd(gcd,num);
    }
    printf("%d\n",gcd);
    return 0;
}
/*
gcd
the process of monster attacks is similar to euclidean algo
so take gcd of all numbers
*/