#include<bits/stdc++.h>
using namespace std;
int main(){  
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,i;
	cin>>n>>k;
	int sum=k;
	
    //create an array with k number of 1s
    int A[k];
	fill(A,A+k,1);

    //starting from the last element and double some of them such that their sum=n
	for (i=k-1;i>=0;--i) {
		while(sum+A[i]<=n){
			sum+=A[i];
			A[i]*=2;
		}
	}
	if(sum!=n){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		for(i=0;i<k;++i){
			cout<<A[i]<<' ';
		}
	}
	return 0;
}