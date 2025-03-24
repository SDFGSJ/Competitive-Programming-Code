n=int(input())

if n%2==1:
    l=r=(n-1)//2
    print('-'*l+'='+'-'*r)
else:
    l=r=(n-2)//2
    print('-'*l+'=='+'-'*r)