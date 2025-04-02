#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[105];   //<num,idx>
int ans[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        p[i]={num,i};
    }

    sort(p,p+n,greater<>());
    int r=1;
    for(int i=0;i<n;){
        int cnt=0,num=p[i].first;
        while(i<n && p[i].first==num){
            ans[p[i].second]=r;
            i++;
            cnt++;
        }
        r+=cnt;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}