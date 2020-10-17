class Solution {
public:
    int integerBreak(int n) {
        if(n==1) return 1;
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        vector<int> dp(n+1);
        dp[1] = 1;dp[2] = 1;dp[3] = 2;dp[4] = 4;
    
        for(int i=5;i<=n;i++){
            dp[i] = dp[i-1]%2 == 0 ? (dp[i-1]/2)*3 : (dp[i-1]/3)*4;
        }
        return dp[n];
        
    }
};

