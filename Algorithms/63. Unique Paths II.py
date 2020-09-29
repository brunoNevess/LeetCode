class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
       
        ## n,m = m,n
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
        
        dp = [ [0 for j in range(m)] for i in range(n) ]
        flag = False
        for i in range(m):
            if obstacleGrid[0][i] == 0 and not flag:
                dp[0][i] = 1
            else:
                flag = True
                dp[0][i] = 0
                
        flag = False
        for i in range(n):
            if obstacleGrid[i][0] == 0 and not flag:
                dp[i][0] = 1
            else:
                flag = True
                dp[i][0] = 0
            
        for i in range(1,n):
            for j in range(1,m):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0 
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[n-1][m-1]