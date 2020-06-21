t = int(input())

for _ in range(t):
    n = int(input().strip())
    a = list(map(int, input().strip().split(' ')))
    b = [a[0]]
    for i in range(1, n - 1):
        if (a[i] > a[i - 1] and a[i] > a[i + 1]) or (a[i] < a[i - 1] and a[i] < a[i + 1]):
            b.append(a[i])
    b.append(a[n - 1])
    print(str(len(b)) + '\n' + ' '.join(list(map(str, b))))
