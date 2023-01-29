#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main(){
    int i,j;
    int r,c,num,cnt=0;
    long long ans=1;
    scanf("%d%d",&r,&c);

    //row
    for(i=0;i<r;i++){
        scanf("%d",&num);
        for(j=0;j<num;j++){
            //if the grid we're going to fill 1 is the other column's end(-1),then the answer must be 0(no such kind puzzle)
            if(a[i][j]==-1){
                printf("0\n");
                return 0;
            }
            a[i][j]=1;
        }
        //if the grid we're going to fill -1 is the other column's middle(1),then the answer must be 0
        if(a[i][j]==1){
            printf("0\n");
            return 0;
        }
        a[i][j]=-1;
    }

    //column
    for(i=0;i<c;i++){
        scanf("%d",&num);
        for(j=0;j<num;j++){
            //if the grid we're going to fill 1 is the other row's end(-1),then the answer must be 0(no such kind puzzle)
            if(a[j][i]==-1){
                printf("0\n");
                return 0;
            }
            a[j][i]=1;
        }
        //if the grid we're going to fill -1 is the other row's middle(1),then the answer must be 0
        if(a[j][i]==1){
            printf("0\n");
            return 0;
        }
        a[j][i]=-1;
    }

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==0){
                cnt++;
            }
        }
    }
    //notice that a full board (cnt==0) has one solution
    while(cnt>0){
        ans*=2;
        ans%=1000000007;
        cnt--;
    }
    printf("%lld\n",ans);
    return 0;
}