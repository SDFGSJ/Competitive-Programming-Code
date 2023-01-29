#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int main(){
    int n,m,i,j,k,cnt=0;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='W'){
                for(k=0;k<4;k++){
                    if(0<=i+di[k] && i+di[k]<n && 0<=j+dj[k] && j+dj[k]<m){
                        if(a[i+di[k]][j+dj[k]]=='P'){
                            a[i][j]=a[i+di[k]][j+dj[k]]='.';
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}