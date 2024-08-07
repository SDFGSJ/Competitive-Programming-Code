#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[105][105];
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&b[i][j]);
        }
    }

    long long ans=0;
    for(int i=0;i+1<h;i++){
        for(int j=0;j+1<w;j++){
            int diff=b[i][j]-a[i][j];
            a[i][j]+=diff;
            a[i+1][j]+=diff;
            a[i][j+1]+=diff;
            a[i+1][j+1]+=diff;
            ans+=abs(diff);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]!=b[i][j]){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n%lld\n",ans);
    return 0;
}