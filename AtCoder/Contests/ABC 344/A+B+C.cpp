#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],c[105];
set<int> s;
int main(){
    int n,m,l,q;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }

    scanf("%d",&l);
    for(int i=0;i<l;i++){
        scanf("%d",&c[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<l;k++){
                s.emplace(a[i]+b[j]+c[k]);
            }
        }
    }

    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        if(*s.lower_bound(x)==x){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}