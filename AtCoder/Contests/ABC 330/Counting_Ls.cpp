#include<bits/stdc++.h>
using namespace std;
char m[2010][2010];
int rowcnt[2010],colcnt[2010];
int main(){
    int n;
    scanf("%d",&n);
    long long ans=0;
    for(int i=0;i<n;i++){
        scanf("%s",m[i]);
        for(int j=0;j<n;j++){
            if(m[i][j]=='o'){
                rowcnt[i]++;
                colcnt[j]++;
            }
        }
    }
    /*for(int i=0;i<n;i++){
        printf("row %d has %d\n",i,rowcnt[i]);
    }
    for(int i=0;i<n;i++){
        printf("col %d has %d\n",i,colcnt[i]);
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]=='o'){
                ans+=(rowcnt[i]-1)*(colcnt[j]-1);
            }
        }
    }
    printf("%lld\n",ans);
    /*for(int i=0;i<n;i++){
        printf("%s",m[i]);
    }*/
    return 0;
}