#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define eps 1e-8
 
bool check(int x, int k, int n)
{
	int cnt = 0;
	LL t = 1;
	while (x/t > 0)
	{
		cnt += x / t;
		t *= k;
	}
	if (cnt >= n) return 1;
	else return 0;
}
 
int main()
{
	int n, k, l, r;
	scanf("%d%d", &n, &k);
	l = 1, r = n;
	while (l < r)
	{
		int mid = (l+r) >> 1;
		if (check(mid, k, n)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l); 
	return 0;
}