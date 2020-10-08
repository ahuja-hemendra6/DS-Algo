class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        # Approach 1 - O(m+n) space
        '''zeros = []
        rows, cols = set(), set()
        n, m = len(matrix), len(matrix[0])
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    if i not in rows:
                        rows.add(i)
                    if j not in cols:
                        cols.add(j)
        for i in rows:
            for j in range(m):
                matrix[i][j] = 0
        for j in cols:
            for i in range(n):
                matrix[i][j] = 0'''
                
        # Approach 2 - O(1) space
        flag = False
        n, m = len(matrix), len(matrix[0])
        for i in range(n):
            if matrix[i][0] == 0:
                flag = True
            for j in range(1, m):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        for i in range(1, n):
            for j in range(1, m):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0
        
        # Check for 0th row
        if not matrix[0][0]:
            for j in range(m):
                matrix[0][j] = 0
        
        if flag:
            for i in range(n):
                matrix[i][0] = 0
        
        