n = int(input())
a = list(map(int, input().strip().split(' ')))
b = 0
ans = [0 for i in range(n)]

counter, mex = 0, 0
present = [False for i in range(n + 1)]
done = [False for i in range(n + 1)]


for el in a:
    present[el] = True

while counter < n and present[counter]:
    counter += 1

for i in range(n):
    if i > 0 and a[i] != a[i - 1]:
        ans[i] = a[i - 1]
    else:
        ans[i] = counter
        counter += 1

    done[ans[i]] = True
    while (done[mex]):
        mex += 1

    if mex != a[i]:
        print(-1)
        exit(0)

    counter = max(counter, ans[i])
    while counter < n and present[counter]:
        counter += 1

print(" ".join(list(map(str, ans))))
