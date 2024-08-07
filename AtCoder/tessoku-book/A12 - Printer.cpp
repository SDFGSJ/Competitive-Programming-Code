#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,k;
bool valid(int sec){
    long long total=0;
    for(int i=0;i<n;i++){
        total+=sec/a[i];
    }
    return total>=k;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int L=0,R=1e9;
    while(L+1<R){
        int mid=L+(R-L)/2;
        if(valid(mid)){
            R=mid;
        }else{
            L=mid;
        }
    }
    printf("%d\n",R);
    return 0;
}