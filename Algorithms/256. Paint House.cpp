class Solution {
public:
    
    int ans = INT_MAX;
    vector<vector<int>> cost;
    int n;
    vector<vector<int>> dp;
    int paint(int house,int last){
        if(house >= n) return 0;
        if(dp[house][last]!=INT_MAX) return dp[house][last];
    
        int res = INT_MAX;
        for(int i=0;i<3;i++){
            if(i!=last) res = min(res,cost[house][i] + paint(house+1,i));
        }
        return dp[house][last] = res;
    }
    
    
    int minCost(vector<vector<int>>& costs) {
        n = costs.size();
        if(n==0) return 0;
        dp.resize(n,vector<int>(4,INT_MAX));
        cost = costs;
        paint(0,3);
        return dp[0][3];
    }
};

