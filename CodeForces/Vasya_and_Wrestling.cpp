#include<bits/stdc++.h>
using namespace std;
int first[200010],second[200010];
int main(){
    int i,j;
    int n,num,fidx=0,sidx=0,fbigger=-1;
    long long f=0,s=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        if(num>0){
            f+=num;
            first[fidx]=num;
            fidx++;
        }else{
            s+=(-num);
            second[sidx]=(-num);
            sidx++;
        }
    }
    if(f>s){
        fbigger=1;
    }else if(f<s){
        fbigger=0;
    }else{
        for(i=0;i<fidx && i<sidx;i++){
            if(first[i]>second[i]){
                fbigger=1;
                break;
            }else if(first[i]<second[i]){
                fbigger=0;
                break;
            }
        }
        if(fbigger==-1 && i==fidx && i==sidx){    //same sum and same sequence,length
            if(num>0){
                fbigger=1;
            }else{
                fbigger=0;
            }
        }
    }
    if(fbigger){
        printf("first\n");
    }else{
        printf("second\n");
    }
    return 0;
}