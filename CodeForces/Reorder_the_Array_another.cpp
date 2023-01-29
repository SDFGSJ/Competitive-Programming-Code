#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    //The answer is n minus maximal number of equal elements. by editorial
    int n,i,Max=-1;
    map<int,int> m; //<number,cnt>
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    for(auto i:m){
        Max=max(Max,i.second);
    }
    printf("%d\n",n-Max);
    return 0;
}