#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int t,i,sum,evencnt;
    bool has_zero;
    scanf("%d",&t);
    while(t--){
        sum=evencnt=0;
        has_zero=false;
        scanf("%s",s);
        for(i=0;s[i]!='\0';i++){
            int num=s[i]-'0';
            sum+=num;
            if(num%2==0){
                evencnt++;
            }
            if(num==0){
                has_zero=true;
            }
        }
        //cout<<has_even<<has_zero<<","<<sum<<"\n";
        if(has_zero && evencnt>=2 && sum%3==0){
            printf("red\n");
        }else{
            printf("cyan\n");
        }
    }
    return 0;
}