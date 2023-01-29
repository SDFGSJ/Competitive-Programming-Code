#include<bits/stdc++.h>
using namespace std;
int seq[300],mono[105],poly[105];
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int k,n,m;
        int zero=0,Max=-1e9,idx=0;
        bool no=false;

        scanf("%d%d%d",&k,&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&mono[i]);
            if(mono[i]==0){
                zero++;
            }
            if(Max<mono[i]){
                Max=mono[i];
            }
        }
        for(i=0;i<m;i++){
            scanf("%d",&poly[i]);
            if(poly[i]==0){
                zero++;
            }
            if(Max<poly[i]){
                Max=poly[i];
            }
        }

        if(k+zero<Max){ //the total number of line is less than the max line number to be changed
            printf("-1\n");
            continue;
        }

        //k:record how many lines(0) now
        i=j=0;
        while(i<n && j<m){
            if(mono[i]==0){
                k++;
                seq[idx]=mono[i];
                idx++;i++;
                continue;
            }
            if(poly[j]==0){
                k++;
                seq[idx]=poly[j];
                idx++;j++;
                continue;
            }

            if(mono[i]<poly[j] && mono[i]<=k){
                seq[idx]=mono[i];
                idx++;i++;
            }else if(poly[j]<=mono[i] && poly[j]<=k){
                seq[idx]=poly[j];
                idx++;j++;
            }else{
                no=true;
                break;
            }
        }
        while(i<n){ //the rest of mono
            if(mono[i]==0){
                k++;
            }
            if(mono[i]<=k){ //the line number to be changed must < the total lines now
                seq[idx]=mono[i];
                idx++;i++;
            }else{
                no=true;
                break;
            }
        }
        while(j<m){ //the rest of poly
            if(poly[j]==0){
                k++;
            }
            if(poly[j]<=k){ //the line number to be changed must < the total lines now
                seq[idx]=poly[j];
                idx++;j++;
            }else{
                no=true;
                break;
            }
        }
        if(no){
            printf("-1\n");
            continue;
        }
        for(i=0;i<idx;i++){
            printf("%d ",seq[i]);
        }
        printf("\n");
    }
    return 0;
}