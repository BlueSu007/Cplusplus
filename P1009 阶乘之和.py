a=eval(input())
ans=0

for i in range(1,a+1):
    b=1
    for j in range(1,i+1):
        b*=j
    ans+=b

print(ans)
