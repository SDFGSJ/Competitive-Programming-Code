#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m;
bool valid(long long width){
    long long chcnt=0,rowcnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>width){ //it's impossible to put a big word into a small place
            return false;
        }

        //break into 3 cases
        if(chcnt+a[i]<width){   //can put ' ' at the back
            chcnt+=a[i]+1;
        }else if(chcnt+a[i]==width){    //this row is just full
            chcnt=0;
            rowcnt++;
        }else{  //cant put this word on this row, write to next line and start on this word again
            rowcnt++;
            chcnt=0;i--;
        }
    }
    if(chcnt>0){    //remaining words form a row
        rowcnt++;
    }
    return rowcnt<=m;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    long long L=0,R=2e15;
    while(L+1<R){
        long long mid=L+(R-L)/2;
        if(valid(mid)){
            R=mid;
        }else{
            L=mid;
        }
    }
    printf("%lld\n",R);
    return 0;
}
//bs