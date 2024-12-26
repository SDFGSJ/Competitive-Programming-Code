#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,set<long long>> X,Y;
int main(){
    int n,m;
    long long sx,sy;
    scanf("%d%d%lld%lld",&n,&m,&sx,&sy);
    for(int i=0;i<n;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        X[x].emplace(y);
        Y[y].emplace(x);
    }

    int cnt=0;
    for(int i=0;i<m;i++){
        char d;
        int c;
        scanf(" %c%d",&d,&c);
        if(d=='U'){ //(x,y) => (x,y+c)
            if(X.find(sx)==X.end()){    //there's no house on the line X=sx
                sy+=c;
                continue;
            }

            //find the # of houses in [sy,sy+c] on line X=sx
            auto upit=X[sx].upper_bound(sy+c);
            auto lowit=X[sx].lower_bound(sy);
            cnt+=distance(lowit,upit);

            //also erase these houses in Y
            for(auto it=lowit;it!=upit;it++){
                Y[*it].erase(sx);
            }

            //if these houses are visited, we can remove them to prevent re-calculation
            X[sx].erase(lowit,upit);
            sy+=c;
        }else if(d=='R'){   //(x,y) => (x+c,y)
            if(Y.find(sy)==Y.end()){
                sx+=c;
                continue;
            }
            auto upit=Y[sy].upper_bound(sx+c);
            auto lowit=Y[sy].lower_bound(sx);
            cnt+=distance(lowit,upit);
            for(auto it=lowit;it!=upit;it++){
                X[*it].erase(sy);
            }

            Y[sy].erase(lowit,upit);
            sx+=c;
        }else if(d=='D'){   //(x,y) => (x,y-c)
            if(X.find(sx)==X.end()){
                sy-=c;
                continue;
            }
            auto upit=X[sx].upper_bound(sy);
            auto lowit=X[sx].lower_bound(sy-c);
            cnt+=distance(lowit,upit);
            for(auto it=lowit;it!=upit;it++){
                Y[*it].erase(sx);
            }

            X[sx].erase(lowit,upit);
            sy-=c;
        }else{  //(x,y) => (x-c,y)
            if(Y.find(sy)==Y.end()){
                sx-=c;
                continue;
            }
            auto upit=Y[sy].upper_bound(sx);
            auto lowit=Y[sy].lower_bound(sx-c);
            cnt+=distance(lowit,upit);
            for(auto it=lowit;it!=upit;it++){
                X[*it].erase(sy);
            }

            Y[sy].erase(lowit,upit);
            sx-=c;
        }
    }
    printf("%lld %lld %d\n",sx,sy,cnt);
    return 0;
}
/*
unordered_map<ll,set<ll>>
X[x] = list of y coordinates of the houses on the vertical line X=x
Y[y] = list of x coordinates of the houses on the horizontal line Y=y
*/