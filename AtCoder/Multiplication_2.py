n=int(input())
a=sorted(list(map(int,input().split())),reverse=True)

result=1
if a[-1]==0:
    result=0
else:
    for i in a:
        result*=i
        if result>10**18:
            result=-1
            break
print(result)