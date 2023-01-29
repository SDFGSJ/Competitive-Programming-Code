#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    set<int> s;
    int n,l,r,mymax,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }


    l=r=0;  //two pointers
    mymax=1;
    s.insert(a[l]);
    while(l<n && r+1<n){
        r++;    //first, move r to the next element

        if(s.count(a[r])>0){    //check if a[r] is already in the set
            int pos=find(a+l,a+r,a[r])-a;   //find the first number that == the duplicate number in [a+l,a+r), and get the index
            for(;l<=pos;l++){   //erase all the element from [l,pos]
                s.erase(a[l]);
            }
            //after this loop,l will be pos+1, which meets our expectation
        }

        s.insert(a[r]); //insert the new number
        mymax=max(mymax,(int)s.size()); //always update the max ans
    }
    printf("%d\n",mymax);
    return 0;
}