import math
a,b=map(int,input().split())
L,R=-1,1e18+1
def f(num_of_b):
    return a/math.sqrt(1+num_of_b) + num_of_b*b
while L+2<R:
    m=L+(R-L)//3
    M=R-(R-L)//3
    if f(m)<f(M):
        R=M
    else:
        L=m
print(f"{f((L+R)/2):.10f}")
"""
ternary search
set eps = 2
"""