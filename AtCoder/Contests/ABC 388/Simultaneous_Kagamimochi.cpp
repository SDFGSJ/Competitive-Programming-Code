#include<bits/stdc++.h>
using namespace std;
int a[500010];
multiset<int> s;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i>=n/2){
            s.emplace(a[i]);
        }
    }

    int ans=0;
    for(int i=0;i<n/2;i++){
        auto it=s.lower_bound(2*a[i]);
        if(it==s.end()){    //there's no suitable base for this mochi
            break;
        }
        ans++;
        s.erase(it);
    }
    printf("%d\n",ans);
    return 0;
}
/*
1 1 2 2 4 5
WA:for each number num, find the smallest number target s.t. target>=2*num, and remove both num and target

we choose the numbers in the second half of the array to be the base of kagamimochis
now we have floor(n/2) bases of mochi
(when n is odd, the (n+1)/2-th mochi can either be the top or base of the mochi and it doesnt affect the ans)
then we try to greedily match the first half of the mochis to those bases
*/