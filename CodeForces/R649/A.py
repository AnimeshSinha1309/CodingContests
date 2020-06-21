t = int(input())

for _ in range(t):
    n, x = list(map(int, input().strip().split(' ')))
    a = list(map(int, input().strip().split(' ')))
    no_ans = True
    for el in a:
        if el % x != 0:
            no_ans = False
    if no_ans:
        print(-1)
    elif sum(a) % x == 0:
        for i in range(n):
            if a[i] % x != 0 or a[n - 1 - i] % x != 0:
                print(n - 1 - i)
                break
    else:
        print(n)
