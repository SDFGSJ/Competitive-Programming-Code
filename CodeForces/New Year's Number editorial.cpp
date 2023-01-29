#include<stdio.h>
int main(void){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n/2020 >= n%2020){
            printf("YES\n");
        }else{
			printf("NO\n");
        }
    }
}
