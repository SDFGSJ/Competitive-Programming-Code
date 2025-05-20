n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
cur=1
for num in a:
    cur*=num
    if len(str(cur))>k:
        cur=1
print(cur)