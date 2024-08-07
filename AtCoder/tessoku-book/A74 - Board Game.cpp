#include<bits/stdc++.h>
using namespace std;
int a[105][105],x[105],y[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                x[i]=y[j]=a[i][j];
            }
        }
    }

    int invx=0,invy=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[i]>x[j]){
                invx++;
            }
            if(y[i]>y[j]){
                invy++;
            }
        }
    }
    printf("%d\n",invx+invy);
    return 0;
}