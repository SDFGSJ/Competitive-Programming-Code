#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    int L=0,R=n+1;
    while(L+1<R){
        int mid=L+(R-L)/2;
        cout<<'?'<<' '<<'1'<<' '<<mid<<' '<<'1'<<' '<<n<<endl;
        int t;
        scanf("%d",&t);
        if(t>=mid){
            L=mid;
        }else{
            R=mid;
        }
    }

    int target_r=R;
    L=0,R=n+1;
    while(L+1<R){
        int mid=L+(R-L)/2;
        cout<<'?'<<' '<<'1'<<' '<<n<<' '<<'1'<<' '<<mid<<endl;
        int t;
        scanf("%d",&t);
        if(t>=mid){
            L=mid;
        }else{
            R=mid;
        }
    }
    int target_c=R;
    cout<<"! "<<target_r<<" "<<target_c<<endl;
    return 0;
}
/*
binary search
first, find the row r s.t. (# of rooks in area (1,1) and (r,n))<r
if # of rooks in the above area is r, that means there are exactly 1 rook on each row from 1 to r
then, find the col c s.t. (# of rooks in area (1,1) and (n,c))<r
if # of rooks in the above area is c, that means there are exactly 1 rook on each col from 1 to c
*/