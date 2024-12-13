#include<bits/stdc++.h>
using namespace std;
int t[200010],x[200010],monster[200010],potion[200010];
deque<int> ans; //support push front so no need to reverse
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&t[i],&x[i]);
    }

    //do in reverse
    for(int i=n-1;i>=0;i--){
        if(t[i]==1){
            if(monster[x[i]]>0){    //there are 1 or more monsters of type x[i] after this potion, need to pick this up
                monster[x[i]]--;
                ans.emplace_front(1);
            }else{  //no monster of type x[i] after this potion, no need to pick this up
                ans.emplace_front(0);
            }
        }else{
            ans.emplace_front(-1);  //emplace -1 to indicate that t[i]=2, no need to print out at the end, convenient for implementaion
            monster[x[i]]++;
        }
    }

    //if there are remaining monsters => we are defeated
    for(int i=1;i<=200000;i++){
        if(monster[i]>0){
            printf("-1\n");
            return 0;
        }
    }

    int M=0,cnt=0;
    for(int i=0;i<n;i++){
        if(ans[i]==1){  //pick up a potion of type x[i]
            potion[x[i]]++;
            cnt++;
        }else if(ans[i]==-1){   //encounter a monster of type x[i]
            potion[x[i]]--;
            cnt--;
        }
        M=max(M,cnt);
    }

    printf("%d\n",M);
    for(auto num:ans){
        if(num!=-1){    //ignore type 2 operation
            printf("%d ",num);
        }
    }
    printf("\n");
    return 0;
}
/*
greedy from the back
monster[i] = # of monster of type i
potion[i] = # of potion of type i
*/