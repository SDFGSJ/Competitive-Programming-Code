#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    int five=0; //the number of factor 5 in n!
    scanf("%d",&n);
    for(i=5;i<=n;i+=5){ //here can speed up
        int tmp=i;
        while(tmp%5==0){
            five++;
            tmp/=5;
        }
    }
    printf("%d\n",five);
    return 0;
}
/*only needs to count how many 5 as factor in n!
the number of 2 must more than 5, so count 5 is enough*/