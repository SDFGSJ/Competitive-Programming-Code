s=input().split('|')
ans=[]
for idx in range(1,len(s)-1):
    ans.append(str(len(s[idx])))
print(" ".join(ans))