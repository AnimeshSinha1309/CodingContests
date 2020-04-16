def solution(n):
    dp = [ [ 0 for i in range(n + 1) ] for j in range(n + 1) ]
    for bricks in range(n + 1):
        for height in range(n + 1):
            if 0 <= bricks <= 1:
                dp[bricks][height] = 1 if height == bricks else 0
            else:
                dp[bricks][height] = sum([
                    dp[bricks - height][prev] 
                    for prev in range(height)
                ])
    # for i in range(n + 1):
    #     for j in range(n + 1):
    #         print(dp[i][j], end=' ')
    #     print()
    return sum(dp[bricks]) - 1
