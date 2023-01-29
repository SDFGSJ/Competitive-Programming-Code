#include<bits/stdc++.h>
using namespace std;
int a[2010],cpy[2010];
map<int,int> m; //<top k value:appear times>
int main(){
    int n,k,i,j,sum=0;

    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        cpy[i]=a[i];
    }

    sort(cpy,cpy+n,greater<int>());
    for(i=0;i<k;i++){
        sum+=cpy[i];
        m[ cpy[i] ]++;
    }
    printf("%d\n",sum);

    for(i=0;i<n;){
        int meet_cnt=0; //the number of top k value in this range
        for(j=i;j<n;j++){
            if(m.count(a[j]) > 0){  //if a[j] is one of the top k values
                meet_cnt++;
                if(meet_cnt>=2){
                    break;
                }
                m[ a[j] ]--;    //if a[j] is the first top k values we meet,a[j] appearance-=1,else do nothing
                if(m[a[j]]==0){
                    m.erase(a[j]);
                }
            }
        }
        j--;    //move to the previous number
        printf("%d ",j-i+1);
        i=j+1;  //move to the next number
    }
    return 0;
}