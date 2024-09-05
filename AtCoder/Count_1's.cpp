/*
solved after reading editorial
#1's we can get after flipping a subarray = #0's - #1's in that subarray
ex. 00001 => we get 4-1=3 more 1's by flipping
view 0 as +1, 1 as -1, and then do prefix sum
the problem remains to find max/min of (prefix[r]-prefix[l])
by fixing r, we can find this in O(n)
since each number is +1 or -1 after mapping, all values in [min,max] is possible
=> ans = max-min+1

max(prefix[r]-prefix[l]) = prefix[r]+max(-prefix[l]) = prefix[r]-min(prefix[l])
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    int sum=0,mymin=0,mymax=0,upper=0,lower=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num==0){
            sum++;
        }else{
            sum--;
        }
        upper=max(upper,sum-mymin);
        lower=min(lower,sum-mymax);
        mymin=min(mymin,sum);
        mymax=max(mymax,sum);
    }
    printf("%d\n",upper-lower+1);
    return 0;
}