class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n,vector<int>(1001));
        int maxLen = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int r = A[i] - A[j] + 500;
                dp[i][r] = dp[j][r] + 1;
                maxLen = max(maxLen,dp[i][r]); 
            }
        }
        return maxLen+1;
        
    }
};



