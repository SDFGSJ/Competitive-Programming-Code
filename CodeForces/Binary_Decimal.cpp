#include<bits/stdc++.h>
using namespace std;
int cnt[15];
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int n,idx=0,ans=0;
        scanf("%d",&n);
        
        //record each digit
        while(n>0){
            cnt[idx++]=n%10;
            n/=10;
        }

        //sort the array and subtract every element with the smallest one
        while(1){
            sort(cnt,cnt+idx);
            //find the first non-zero element
            i=0;
            while(cnt[i]==0){
                i++;
            }
            //break the loop when there's only one number left
            if(i>=idx-1){
                break;
            }

            for(j=i+1;j<idx;j++){
                cnt[j]-=cnt[i];
            }

            ans+=cnt[i];
            cnt[i]=0;   //remember to set the smallest element to 0
        }
        ans+=cnt[idx-1];    //remember to add the last number
        printf("%d\n",ans);
    }
    return 0;
}