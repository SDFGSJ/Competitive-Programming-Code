#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    multiset<int> s;    //beware of duplicate values
    int n,tower=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        auto it=s.upper_bound(a[i]);
        if(it==s.end()){    //cant put on any tower
            tower++;
            s.insert(a[i]);
        }else{  //put on tower & update the value to be the top number
            s.erase(it);
            s.insert(a[i]);
        }
    }
    printf("%d\n",tower);
    return 0;
}