#include<bits/stdc++.h>
using namespace std;
pair<int,int> stu[55],check[55];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&stu[i].first,&stu[i].second);
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&check[i].first,&check[i].second);
    }
    for(int i=0;i<n;i++){
        auto [x1,y1]=stu[i];
        int mymin=INT_MAX,ans=-1;
        for(int j=m-1;j>=0;j--){
            auto [x2,y2]=check[j];
            int dist=abs(x1-x2)+abs(y1-y2);
            if(dist<=mymin){
                mymin=dist;
                ans=j;
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}