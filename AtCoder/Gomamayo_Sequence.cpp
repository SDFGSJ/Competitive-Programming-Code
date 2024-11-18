#include<bits/stdc++.h>
using namespace std;
char s[200010];
int c[200010];
long long zero[200010],one[200010];
int main(){
    int n;
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }

    int bit=0;
    for(int i=1;i<=n;i++){
        int num=s[i]-'0';
        zero[i]=zero[i-1];
        if(num^bit){
            zero[i]+=c[i];
        }

        one[i]=one[i-1];
        if(num^(1-bit)){
            one[i]+=c[i];
        }
        bit=1-bit;
    }

    long long ans=LONG_LONG_MAX;
    for(int i=1;i+1<=n;i++){
        long long first=zero[i]+one[n]-one[i];
        long long second=one[i]+zero[n]-zero[i];
        ans=min({ans,first,second});
    }
    printf("%lld\n",ans);
    return 0;
}
/*
zero[i] = cost to make s[1~i] into 01010...[1~i]
one[i] = cost to make s[1~i] into 10101...[1~i]
maintain prefix sum to obtain 010...010 and 101...101, then use 2-pointers
0](1010
1)[0101
][ => zero's prefix + one's suffix => zero[i]+(one[n]-one[i])
)( => one's prefix + zero's suffix => one[i]+(zero[n]-zero[i])
*/