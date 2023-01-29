#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int s1,s2,s3,s4;
        scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
        int first,second;
        if(s1>s2){
            first=s1;
        }else{
            first=s2;
        }
        if(s3>s4){
            second=s3;
        }else{
            second=s4;
        }
        if(first==s1){
            if(second==s3){
                if(s1>s4 && s3>s2){
                    printf("yes\n");
                }else{
                    printf("no\n");
                }
            }else{  //second==s4
                if(s1>s3 && s4>s2){
                    printf("yes\n");
                }else{
                    printf("no\n");
                }
            }
        }else{  //first==s2
            if(second==s3){
                if(s2>s4 && s3>s1){
                    printf("yes\n");
                }else{
                    printf("no\n");
                }
            }else{  //second==s4
                if(s2>s3 && s4>s1){
                    printf("yes\n");
                }else{
                    printf("no\n");
                }
            }
        }
    }
    return 0;
};