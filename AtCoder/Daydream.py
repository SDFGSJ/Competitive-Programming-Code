str=input()
ans=[]
for l in str.split('dream'):
    ans+=l.split('erase')

good=True
for word in ans:
    if word not in ['','r','er']:
        good=False

if good:
    print('YES')
else:
    print('NO')