class Solution {
public:
    
    // n-1 digits + with n digits -> n digits -> 
    
    int c(int n){
        int p = 9,w = 9;
        for(int i=0;i<n-1;i++){
            p = p*w;
            w--;
        }
        return p;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        vector<int> dp(n+1);
        dp[1] = 10;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + c(i);
        }
        return dp[n]; 
    }
};