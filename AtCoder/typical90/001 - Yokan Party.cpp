//solved after reading editorial
#include<bits/stdc++.h>
using namespace std;
int a[100010];
vector<int> gap;
bool valid(int len, int k, int n){ //return true if we can produce >= k+1 piece with length >= len
    int sum=0,piece=0;
    for(int i=0;i<gap.size();i++){
        sum+=gap[i];
        if(sum>=len){
            piece++;
            sum=0;
        }
    }
    return piece>=k+1;
}
int main(){
    int n,l,k;
    scanf("%d%d%d",&n,&l,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    gap.emplace_back(a[0]);
    for(int i=1;i<n;i++){
        gap.emplace_back(a[i]-a[i-1]);
    }
    gap.emplace_back(l-a[n-1]);

    int L=0,R=l;
    while(L+1<R){
        int mid=L+(R-L)/2;
        if(valid(mid, k, n)){
            L=mid;
        }else{
            R=mid;
        }
    }
    printf("%d\n",L);
    return 0;
}