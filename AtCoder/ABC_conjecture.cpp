#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    scanf("%lld",&N);
    long long ans=0;
    for(long long A=1;A*A*A<=N;A++){
        for(long long B=A;B*B<=N/A;B++){
            ans+=(N/A/B - (B-1));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
enumerate A=1~cubic root(N), B=A~sqrt(N/A), then C=N/(AB)
since B<=C, which means C can not be 1~(B-1), so needs to substract (B-1) from C

Range of enumeration:
from problem description, we have:
1. A<=A && A<=B && A<=C => AAA<=ABC<=N => 1<=A<=cubic root(N)
2. ABC<=N => BC<=N/A
3. B<=C => multiply B on both sides => BB<=BC<=N/A
so A<=B<=sqrt(N/A)
*/