#include<stdio.h>
int main(void)
{
	int t,i;
	long long a[3];
	scanf("%d",&t);
	while(t--){
		long long m,num=0,min=1e18;
		scanf("%lld%lld%lld%lld",&m,&a[0],&a[1],&a[2]);
		for(i=0;i<3;i++){
			if(m<=a[i]){
				num=a[i]-m;
			}else{
				if(m%a[i]==0){	//�p�G�i�H�㰣����min�N�@�w�O0�F�A�����~��]�j�� 
					min=0;
					break;
				}else{
					num=a[i]-m%a[i];
				}
			}
			if(num<min)	min=num;
		}
		printf("%lld\n",min);
	}
	return 0;
}
