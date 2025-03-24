#include<bits/stdc++.h>
using namespace std;
int a[300010];
unordered_map<int,int> um;  //<num,cnt>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        um[a[i]]++;
    }

    int mymax=-1,idx=0;
    for(int i=n;i>=1;i--){
        if(um[a[i]]==1 && mymax<a[i]){
            mymax=a[i];
            idx=i;
        }
    }
    if(idx==0){
        idx=-1;
    }
    printf("%d\n",idx);
    return 0;
}
/*
simulation using hash map
*/