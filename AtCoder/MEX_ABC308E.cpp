#include<bits/stdc++.h>
using namespace std;
int a[200010];
char s[200010];
int preM[200010][3], preX[200010][3];
int n;
int find_mex(int a,int b,int c){    //mex(a,b,c)
    for(int i=0;i<=2;i++){
        if(i!=a && i!=b && i!=c){
            return i;
        }
    }
    return 3;
}
long long calc(int idx){  //s[idx]=='E'
    long long res=0;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            int left_M_cnt=preM[idx-1][i];  //# of 'M' in [1,idx-1]
            int right_X_cnt=preX[n][j]-preX[idx][j];    //# of 'X' in [idx+1,n]
            res+=1ll*find_mex(i,j,a[idx])*left_M_cnt*right_X_cnt;
        }
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%s",s+1);

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            preM[i][j]=preM[i-1][j];
            preX[i][j]=preX[i-1][j];
        }

        if(s[i]=='M'){
            preM[i][a[i]]++;
        }else if(s[i]=='X'){
            preX[i][a[i]]++;
        }
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='E'){
            ans+=calc(i);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
prefix sum
preM[i][j] = # of indexes in [1,i] s.t. s[idx]=='M' and a[idx]==j = |{i | s[i]=='M' && a[i]==j}|
preX[i][j] = # of indexes in [1,i] s.t. s[idx]=='X' and a[idx]==j
focus on the middle of "MEX", which is 'E'
enumerate every position pos of 'E'
let L = # of (M,0)(M,1)(M,2) on left(in [1, pos-1])
R = # of (X,0)(X,1)(X,2) on right(in [pos+1, n])
then there are L*R combinations that can form a "MEX" string
multiply their mex and sum them up to get ans
*/