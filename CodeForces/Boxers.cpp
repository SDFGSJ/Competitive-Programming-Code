#include<bits/stdc++.h>
using namespace std;
int a[150010];
int main(){
    set<int> s;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(a[i]-1!=0 && s.count(a[i]-1)==0){
            s.insert(a[i]-1);
        }else if(s.count(a[i])==0){
            s.insert(a[i]);
        }else{
            s.insert(a[i]+1);
        }
    }
    printf("%d\n",s.size()-s.count(0));
    return 0;
}