class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        m = len(matrix[0])
        zeroRow = False
        zeroColumn = False
        for i in range(0,n):
                if matrix[i][0] == 0:
                        zeroColumn = True
                        break
        for j in range(0,m):
                if matrix[0][j] == 0:
                        zeroRow = True
                        break
        for i in range(1,n):
                for j in range(1,m):
                        if matrix[i][j] == 0:
                                matrix[0][j] = 0
                                matrix[i][0] = 0
        for i in range(1,n):
                if matrix[i][0] == 0:
                        for j in range(0,m):
                                matrix[i][j] = 0
        for j in range(1,m):
                if matrix[0][j] == 0:
                        for i in range(0,n):
                                matrix[i][j] = 0
        if zeroColumn:
                for i in range(0,n):
                        matrix[i][0] = 0
        if zeroRow:
                for i in range(0,m):
                        matrix[0][i] = 0