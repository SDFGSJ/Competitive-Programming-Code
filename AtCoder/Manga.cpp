#include<bits/stdc++.h>
using namespace std;
int a[300010];
deque<int> dq;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int unique_nums=unique(a,a+n)-a;    //# of unique numbers in a[]
    for(int i=0;i<unique_nums;i++){
        dq.emplace_back(a[i]);
    }
    for(int i=0;i<n-unique_nums;i++){   //the remaining duplicate books can be viewed as having arbitrary volume
        dq.emplace_back(INT_MAX);
    }

    int target=1;   //next series we want to read
    while(!dq.empty()){
        if(dq.front()==target){
            dq.pop_front();
            target++;
        }else{
            if(dq.size()>=2){   //sell the last 2 books to get the target volume
                dq.pop_back();dq.pop_back();
                target++;
            }else{  //dont have enough book to sell, terminate the process
                break;
            }
        }
    }
    printf("%d\n",target-1);
    return 0;
}
/*
deque + greedy simulation
sort + take the unique part + transform to deque
*/