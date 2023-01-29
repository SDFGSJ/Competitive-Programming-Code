#include<bits/stdc++.h>
using namespace std;
int my[100010],op[100010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,mysum=0,opsum=0,cnt=0,myidx=0,opidx=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&my[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&op[i]);
        }
        sort(my,my+n,greater<int>());
        sort(op,op+n,greater<int>());
        myidx = opidx = n-(n/4) - 1;
        for(i=0;i<n-(n/4);i++){
            mysum+=my[i];
            opsum+=op[i];
        }
        
        /*printf("my[]=");
        for(i=0;i<n;i++){
            printf("%d,",my[i]);
        }
        printf("\nop[]=");
        for(i=0;i<n;i++){
            printf("%d,",op[i]);
        }
        printf("\n");
        printf("myidx=%d\nopidx=%d\nmysum=%d\nopsum=%d\n",myidx,opidx,mysum,opsum);*/
        if(mysum>=opsum){
            printf("0\n");
            continue;
        }
        while(mysum<opsum){
            mysum+=100;
            cnt++;
            if((n+cnt)%4==0 && myidx>=0){
                mysum-=my[myidx];
                myidx--;
            }
            if(opidx + 1 < (n+cnt) - (n+cnt)/4 && opidx+1<n){
                opidx++;
                opsum+=op[opidx];
            }
            //printf("mysum=%d,opsum=%d\n",mysum,opsum);
        }
        printf("%d\n",cnt);
    }
    return 0;
}