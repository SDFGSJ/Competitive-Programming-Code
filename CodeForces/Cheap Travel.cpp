#include<stdio.h>
int min(int a,int b){
	if(a>b)	return b;
	else return a;
}
int main(void)
{
	int plan,m,one_price,m_price;
	int one,one_two,two;	//全部買單程票、多程+單程、全部多程 
	int ans;
	scanf("%d%d%d%d",&plan,&m,&one_price,&m_price);
	one=plan*one_price;
	one_two=(plan/m)*m_price+(plan%m)*one_price;
	if(plan%m==0){
		two=(plan/m)*m_price;
	}else{
		two=((plan/m)+1)*m_price;
	}
	
	ans=min(one,one_two);
	ans=min(ans,two);
	printf("%d\n",ans);
	return 0;
}
