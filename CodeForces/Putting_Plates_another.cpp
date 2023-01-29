#include <bits/stdc++.h>
using namespace std;
char ch[25][25];
int main(){
    int t,i,j;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        /*for(i=0;i<n+2;i++){
            for(j=0;j<m+2;j++){
                ch[i][j]='0';
            }
        }*/
        memset(ch,'0',sizeof(ch));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                //check the 8 surrounding blocks
                if( ch[i-1][j]=='0' && ch[i-1][j-1]=='0' && ch[i-1][j+1]=='0' && ch[i][j-1]=='0' && ch[i][j]=='0' && \
                    ch[i][j+1]=='0' && ch[i+1][j-1]=='0' && ch[i+1][j]=='0' && ch[i+1][j+1]=='0'){
                    if(i==1 || j==1 || i==n || j==m){   //on the edge
                        cout<<1;
                        ch[i][j]='1';
                    }else{
                        cout<<0;
                        ch[i][j]='0';
                    }
                }else{
                    cout<<0;
                    ch[i][j]='0';
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}