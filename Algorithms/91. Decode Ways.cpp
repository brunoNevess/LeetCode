class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0); // dp[n] -> number of ways with length n
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0:1;
        
        for(int i=2;i<=n;i++){
            int n1 = stoi(s.substr(i-1,1));
            int n2 = stoi(s.substr(i-2,2));
            if(n1>=1 and n1<=9) dp[i] += dp[i-1];
            if(n2>=10 and n2<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};