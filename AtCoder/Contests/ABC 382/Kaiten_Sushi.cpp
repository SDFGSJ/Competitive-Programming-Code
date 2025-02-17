#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200010];    //<val,idx>
int premin[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a,a+n);

    premin[0]=a[0].second;
    for(int i=1;i<n;i++){
        premin[i]=min(premin[i-1],a[i].second);
    }
    for(int i=0;i<m;i++){
        int b;
        scanf("%d",&b);
        int idx=upper_bound(a,a+n,make_pair(b,INT_MAX))-a;
        if(idx==0){
            printf("-1\n");
        }else{
            printf("%d\n",premin[idx-1]+1);
        }
    }
    return 0;
}
/*
premin[i] = min{a[0], a[1], ..., a[i]}
there might be multiple customers with same gourmet level, so use upper bound
idx=0 means this sushi's deliciousness is less than everyone's gourmet level => no one will eat
so the sushi will be eaten by the customer with min id among a[0 ~ idx-1]
*/