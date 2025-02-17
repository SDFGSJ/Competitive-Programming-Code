#include<bits/stdc++.h>
using namespace std;
char s[500010];
int main(){
    int n,q;
    scanf("%d%d%s",&n,&q,s);
    int offset=0;
    while(q--){
        int t,x;
        scanf("%d%d",&t,&x);
        if(t==1){
            offset=(offset+x)%n;
        }else{
            x--;
            int idx=((x-offset)%n+n)%n;
            printf("%c\n",s[idx]);
        }
    }
    return 0;
}
/*
type 1 operation is the same as shifting the string right k times
maintain an offset var to record the shifting times
the x-th char after right shift "offset" times is (((x-1)-offset)%len + len) % len
0-indexed
*/