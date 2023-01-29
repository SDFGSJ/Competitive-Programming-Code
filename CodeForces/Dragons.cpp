#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1010];  //<dragon's strength,bonus>
int main(){
    int s,n,i;
    bool no=false;
    scanf("%d%d",&s,&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(s>a[i].first){
            s+=a[i].second;
        }else{
            no=true;
            break;
        }
    }
    if(!no){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}