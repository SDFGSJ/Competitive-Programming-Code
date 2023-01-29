#include<bits/stdc++.h>
using namespace std;
struct seg{
	int left,right;
	seg(int l,int r):left(l),right(r){}
};
struct cmp{
	bool operator()(const seg& lhs,const seg& rhs) const {
		int l_len = lhs.right-lhs.left;
		int r_len = rhs.right-rhs.left;
		if(l_len != r_len){
			return l_len > r_len;
		}else{
			return lhs.left < rhs.left;
		}
	}
};
int main(){
    int len,n,p,i;
    set<seg,cmp> segment;
    set<int> s; //record every street lights' pos, with 0,x inside initially
    
    scanf("%d%d",&len,&n);
    segment.insert(seg(0,len));
    s.insert(0);
    s.insert(len);
    for(i=0;i<n;i++){
        scanf("%d",&p);
        s.insert(p);

        //find p's neighbors
        auto it=s.lower_bound(p);
        auto left_it=it, right_it=it;
        int l=*(--left_it);
        int r=*(++right_it);
        
        //use the neighbors to find the desire range that covers p
        auto seg_it = segment.lower_bound(seg(l,r));
        segment.insert(seg(seg_it->left, p));    //insert new segment
        segment.insert(seg(p, seg_it->right));
        segment.erase(seg_it);  //remove old segment

        //take out the one with max len
        auto max_len_seg = *segment.begin();    //type=seg
        printf("%d ", max_len_seg.right - max_len_seg.left);
    }
    return 0;
}