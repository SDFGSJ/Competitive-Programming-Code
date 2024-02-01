#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100010],b[100010];  //<price,idx>
set<pair<int,int>> unavail; //<main,side>
set<int> ans;
int main(){
    int n,m,l;
    scanf("%d%d%d",&n,&m,&l);
    for(int i=0;i<n;i++){   //main
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    for(int i=0;i<m;i++){   //side
        scanf("%d",&b[i].first);
        b[i].second=i;
    }
    for(int i=0;i<l;i++){
        int c,d;    //main, side
        scanf("%d%d",&c,&d);
        c--,d--;
        unavail.emplace(c,d);
    }

    sort(b,b+m,greater<>());    //sort side dishes in price desc
    for(int i=0;i<n;i++){   //for each main dish
        for(int j=0;j<m;j++){   //find the side dish that maximize the sum
            if(!unavail.count({a[i].second,b[j].second})){
                ans.emplace(a[i].first+b[j].first);
                break;
            }
        }
    }
    printf("%d\n",*ans.rbegin());
    return 0;
}