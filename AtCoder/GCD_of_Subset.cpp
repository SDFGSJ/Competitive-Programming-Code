#include<bits/stdc++.h>
using namespace std;
int a[1200010],cnt[1000010],ans[1000010];
void eratos(int n,int k){
    for(int i=1;i<=1000000;i++){
        vector<int> nums;
        int total=0;
        for(int j=i;j<=1000000;j+=i){
            if(cnt[j]){ //j exists in a[]
                total+=cnt[j];
                nums.emplace_back(j);
            }
        }
        if(total>=k){   //we have chosen >=k elements
            for(auto num:nums){
                ans[num]=i; //the max gcd of when choosing these numbers can be i
            }
        }
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }

    eratos(n,k);

    for(int i=0;i<n;i++){
        printf("%d\n",ans[a[i]]);
    }
    return 0;
}
/*
modified eratosthenes
cnt[i] = |{idx | a[idx]==i}|
ans[i] = max gcd of number i when choosing k elements
might have duplicate numbers in a[]
enumerate i from 1 to 1e6, if j=(multiple of i) exists in a[], then we push j to a vector
if vector size>=k
    it means that i can be a gcd of those numbers in the vector
    hence we update j's max gcd to i when choosing these numbers
*/