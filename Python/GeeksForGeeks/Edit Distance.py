def do(arr1, n, arr2, m)    
    dp = [[0 for x in range(m+1)] for x in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if j == 0:
                dp[i][j] = i
            elif i == 0:
                dp[i][j] = j
            elif arr1[i-1] == arr2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
    return dp[n][m]

for tc in range(int(input())):
    n, m = list(map(int, input().split()))
    arr1, arr2 = list(input().split())
    print(do(arr1, n, arr2, m))