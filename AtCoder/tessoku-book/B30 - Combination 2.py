import math
h,w=map(int,input().split())
print(math.comb(h+w-2,h-1)%1000000007)