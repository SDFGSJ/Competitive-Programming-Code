#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int gcd=a[0];
    for(int i=1;i<n;i++){
        gcd=__gcd(gcd,a[i]);
    }

    if(gcd!=1){
        for(int i=0;i<n;i++){
            a[i]/=gcd;
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        while(a[i]%2==0){
            a[i]/=2;
            cnt++;
        }
        while(a[i]%3==0){
            a[i]/=3;
            cnt++;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]!=a[0]){
            cnt=-1;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
/*
gcd
let num be the number that every a[i] equals to at the end
if num != 1, means that every a[i] has a common divisor = num in the beginning
so we find the gcd of every a[i] and divide a[i] by gcd
then the problem remains to make every a[i] to 1 in the end
we try to divide every a[i] by 2 or 3 as much as possible
if each a[i] results in 1 in the end, the # of op is the ans
if there exists an a[i] other than 1, then the ans is -1
*/