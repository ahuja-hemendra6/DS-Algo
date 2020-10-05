class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def dfs(i, j):
            if board[i][j] == 'a' or board[i][j] == 'X':
                return
            board[i][j] = 'a'
            for (x, y) in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                if 0 <= x < n and 0 <= y < m:
                    dfs(x, y)
        
        if not board or not board[0]:
            return
        n, m = len(board), len(board[0])
        for i in [0, n-1]:
            for j in range(m):
                if board[i][j] == 'O':
                    dfs(i, j)
                    
        for i in [0, m-1]:
            for j in range(n):
                if board[j][i] == 'O':
                    dfs(j, i)
     
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'a':
                    board[i][j] = 'O'