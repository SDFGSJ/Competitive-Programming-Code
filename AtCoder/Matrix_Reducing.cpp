#include<bits/stdc++.h>
using namespace std;
bool same(int rowbit,int colbit,int H,int W,vector<vector<int>>& A,vector<int>& B){
    vector<int> res;
    for(int i=0;i<H;i++){
        if(rowbit&(1<<i)){  //row i is removed, skip this row
            continue;
        }
        for(int j=0;j<W;j++){
            if(colbit&(1<<j)){  //col j is removed, skip this col
                continue;
            }
            res.emplace_back(A[i][j]);
        }
    }
    return res==B;
}
int main(){
    int H1,W1;
    scanf("%d%d",&H1,&W1);
    vector<vector<int>> A(H1,vector<int>(W1,0));
    for(int i=0;i<H1;i++){
        for(int j=0;j<W1;j++){
            scanf("%d",&A[i][j]);
        }
    }
    int H2,W2;
    scanf("%d%d",&H2,&W2);
    vector<int> B(H2*W2,0); //view B as a 1D array for easier comparison
    for(int i=0;i<H2*W2;i++){
        scanf("%d",&B[i]);
    }

    for(int rowbit=0;rowbit<(1<<H1);rowbit++){
        if(__builtin_popcount(rowbit)!=H1-H2){  //H1-H2 is the # of rows to be removed
            continue;
        }
        for(int colbit=0;colbit<(1<<W1);colbit++){
            if(__builtin_popcount(colbit)!=W1-W2){  //W1-W2 is the # of cols to be removed
                continue;
            }
            if(same(rowbit,colbit,H1,W1,A,B)){
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
/*
bit enumeration
bitmask[i] = 1 means remove i-th row/col
*/