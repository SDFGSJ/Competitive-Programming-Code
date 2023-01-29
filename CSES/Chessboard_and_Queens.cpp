#include<bits/stdc++.h>
using namespace std;
int ans,q[20];
char m[10][10];

void place(int);
int valid(int, int);
int main(){
    int i;
    for(i=0;i<8;i++){
        scanf("%s",m[i]);
    }
	place(0);
	printf("%d",ans);
	return 0;
}
void place(int row){
	int i;
	if(row==8){
		ans++;
	}else{
		for(i=0;i<8;i++){
			if(m[row][i]!='*' && valid(row,i) ){
				q[row]=i;
				place(row+1);
			}
		}	
	}
}
int valid(int row,int col){
	int i;
	for(i=0;i<row;i++){
		if(q[i]==col || q[i]-col==row-i || q[i]-col==i-row){
			return 0;
		}
	}
	return 1;
}