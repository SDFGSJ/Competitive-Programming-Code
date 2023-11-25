#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        sum+=num-1;
    }
    printf("%lld\n",sum);
    return 0;
}