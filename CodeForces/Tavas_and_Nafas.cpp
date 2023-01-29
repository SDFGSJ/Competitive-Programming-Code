#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    string head[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string tail[]={"","one","two","three","four","five","six","seven","eight","nine"};

    if(n==0){
        printf("zero\n");
    }else if(n/10==0){
        cout<<tail[n%10]<<'\n';
    }else if(n==10){
        printf("ten\n");
    }else if(n/10==1){
        switch(n%10){
            case 1: printf("eleven\n"); break;
            case 2: printf("twelve\n"); break;
            case 3: printf("thirteen\n"); break;
            case 4: printf("fourteen\n"); break;
            case 5: printf("fifteen\n"); break;
            case 6: printf("sixteen\n"); break;
            case 7: printf("seventeen\n"); break;
            case 8: printf("eighteen\n"); break;
            case 9: printf("nineteen\n"); break;
        }
    }else if(n%10==0){
        cout<<head[n/10]<<'\n';
    }else{
        cout<<head[n/10]<<"-"<<tail[n%10]<<'\n';
    }
    return 0;
}