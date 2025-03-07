#include<bits/stdc++.h>
using namespace std;
int pigeon2bag[1000010],bag2nest[1000010],nest2bag[1000010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++){
        pigeon2bag[i]=bag2nest[i]=nest2bag[i]=i;
    }

    while(q--){
        int op,a;
        scanf("%d%d",&op,&a);
        if(op==1){
            int b;
            scanf("%d",&b);
            pigeon2bag[a]=nest2bag[b];
        }else if(op==2){
            int b;
            scanf("%d",&b);
            swap(bag2nest[nest2bag[a]],bag2nest[nest2bag[b]]);
            swap(nest2bag[a],nest2bag[b]);
        }else{
            printf("%d\n",bag2nest[pigeon2bag[a]]);
        }
    }
    return 0;
}
/*
idea:
it is time-consuming to swap 2 nests of pigeons, so we put all pigeons in a nest into 1 bag
so we only need to swap the bags when swapping 2 nests of pigeons
=> nest contains bag, bag contains pigeons
pigeon2bag[i] = which bag is pigeon i inside?
bag2nest[i] = which nest is bag i at?
nest2bag[i] = which bag does nest i contains?

Editorial video watched
*/