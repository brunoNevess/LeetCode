class Solution {
public:
    string longestPalindrome(string s) {
        
        
        //dp[i,j] = true if S(i,j) is palindorme
        // dp[i,j] = dp[i+1,j-1] if s[i] == s[j]
        if(s=="") return "";
        int n = s.size();
        int ini = 0,len =0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) {
            dp[i][i] = true;
            if(i+1<n) {
                dp[i][i+1] = (s[i] == s[i+1]);
                if(dp[i][i+1]){
                    ini = i;len = 1;
                }
            }
        }
      
        for(int l=2;l<n;l++){
            for(int i=0;i+l<n;i++){
                   int j = i+l;
                   dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
                   if(dp[i][j] and len < l){
                       ini = i;
                       len = l;
                   }
            }
        }
      
        return s.substr(ini,len+1);
    }
};
