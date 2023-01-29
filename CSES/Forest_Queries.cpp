#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int prefix[1010][1010];   //number of trees on each row
int main(){
    int n,q,i,j;
    scanf("%d%d",&n,&q);

    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }

    //1-indexed
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i-1][j-1]=='*'){
                prefix[i][j]=prefix[i][j-1]+1;
            }else{
                prefix[i][j]=prefix[i][j-1];
            }
        }
    }

    for(i=0;i<q;i++){
        int i1,j1,i2,j2,ans=0;
        scanf("%d%d%d%d",&i1,&j1,&i2,&j2);

        for(j=i1;j<=i2;j++){    //from row i1 to i2,find each row's prefix sum
            ans += prefix[j][j2]-prefix[j][j1-1];
        }

        printf("%d\n",ans);
    }
    return 0;
}