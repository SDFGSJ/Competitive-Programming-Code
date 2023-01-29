#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100010];    //<value,idx>
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,k,cnt=0;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){
            scanf("%d",&a[i].first);
            a[i].second=i;
        }

        sort(a,a+n);
        for(i=0;i+1<n;i++){
            if(a[i+1].second-a[i].second!=1){
                cnt++;
            }
        }
        
        //the minimum number of segments = cnt+1
        if(k<cnt+1){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    return 0;
}