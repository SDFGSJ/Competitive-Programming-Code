#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,num,i;
    multiset<int> s;    //may have duplicate numbers
    
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        s.insert(num);
    }

    for(i=0;i<m;i++){
        scanf("%d",&num);
        if(s.empty()){  //no tickets => cant give out
            printf("-1\n");
        }else{
            auto it=s.lower_bound(num);
            if(it==s.end()){    //dont exist a num >= *it
                //check the previous one
                if(num < *prev(it)){
                    printf("-1\n");
                }else{
                    printf("%d\n",*prev(it));
                    s.erase(prev(it));
                }
            }else{
                if(*it > num){  //the found number > customer's max
                    if(it!=s.begin()){  //move one front
                        printf("%d\n",*prev(it));
                        s.erase(prev(it));
                    }else{
                        printf("-1\n");
                    }
                }else{
                    printf("%d\n",*it);
                    s.erase(it);
                }
            }
        }
    }
    return 0;
}