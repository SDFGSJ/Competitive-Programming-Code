#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].first,&p[i].second);
    }
    for(int i=0;i<n;i++){
        int mymax=0,ans=0;
        for(int j=0;j<n;j++){
            int dx=abs(p[i].first-p[j].first);
            int dy=abs(p[i].second-p[j].second);
            if(dx*dx+dy*dy>mymax){
                mymax=dx*dx+dy*dy;
                ans=j+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}