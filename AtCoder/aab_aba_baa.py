import math
a,b,k=map(int,input().split())

n=a+b
while n!=0:
    n-=1
    if a>=1 and k<=math.comb(n,a-1):
        print('a',end='')
        a-=1    #used up 1 'a'
    else:
        print('b',end='')
        b-=1    #used up 1 'b'
        if a>=1:
            k-=math.comb(n,a-1)
"""
'a'*A & 'b'*B

a
a
.
.
.
a   (A-1+B)!/(A-1)!B!
===
b
b
.
.
.
b   (A-1+B)!/A!(B-1)!
^
|
1st char

if k is in the first half, get a subproblem of 'a'*(A-1) & 'b'*B
if k is in the second half, get a subproblem of 'a'*A & 'b'*(B-1)
"""