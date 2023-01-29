#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        long long a,b,sum=0,total;
        scanf("%lld%lld",&a,&b);

        for(i=0;;i++){
            sum+=i;
            total=a+b+sum;
            if( total%2==0 && total/2>=max(a,b)){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
/*
suppose both number is "final" in the end
(final-a) + (final-b) = 1 + 2 + 3 + ... + x
2*final = a + b + x(x+1)/2 
since a+b is const,we only need to enumerate x(x+1)/2 (a prefix sum which can be maintain by O(1) space)
if right hand side is even and RHS/2 = final >= max(a,b),then current i is the answer
*/