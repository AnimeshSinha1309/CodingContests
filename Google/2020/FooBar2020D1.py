def solution(times, time_limit):
    dists = times.copy()
    n = len(dists)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j])
    if any([dists[i][i] < 0 for i in range(n)]):
        return list(range(n))
    