#include<bits/stdc++.h>
using namespace std;
int n,k,v,sum;
int main(){
    cin>>n>>k;
    int L=1,R=n,mid;
    if(n<=k){
        cout<<n<<endl;
        continue;
    }
    while(L<R){
        mid=L+(R-L)/2;
        v=mid;
        sum=v;
        while(v!=0){
            sum+=v/k;
            v=v/k;
        }
        if(sum<n)
            L=mid+1;
        else
            R=mid;
    }
    cout<<L<<endl;
    return 0;
}