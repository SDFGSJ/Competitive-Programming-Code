#include<bits/stdc++.h>
using namespace std;
int a[400010];
long long pre[400010];
int main(){
    int n;long long s,total=0;
    scanf("%d%lld",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        total+=a[i];
        a[i+n]=a[i];
    }
    s%=total;

    for(int i=1;i<=2*n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    for(int l=1;l<=n;l++){
        long long target=s+pre[l-1];
        auto it=lower_bound(pre,pre+2*n,target);
        if(*it==target){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
/*
if s >= sum of all a[i], then that means the final contiguous subsequence contains some complete A
by doing s%=total, we can simplify the problem from A=infinite seq to A=2N-length seq
the problem remains to find whether there exists 1<=l,r<=2N s.t. a[l]+...+a[r] = pre[r]-pre[l-1] is s
prefix sum + enumerate all positions of l and check if s+pre[l-1] exists or not
*/