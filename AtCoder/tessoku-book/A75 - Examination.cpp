#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[105];
bool cmp(const pair<int,int> a,const pair<int,int> b){
    if(a.second-a.first != b.second-b.first){
        return a.second-a.first < b.second-b.first;
    }
    return a.second<b.second;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }

    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        printf("%d %d\n",a[i].first,a[i].second);
    }

    int cur_time=0,ans=0;
    for(int i=0;i<n;i++){
        if(a[i].second-a[i].first<0){
            continue;
        }

    }
    return 0;
}