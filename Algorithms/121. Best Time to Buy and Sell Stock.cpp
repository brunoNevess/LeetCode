class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1 or prices.size()==0) return 0;
        
        int ans = INT_MIN;
        
        for(int i=1;i<prices.size();i++){
            ans = max(ans,prices[i]-prices[i-1]);
            prices[i] = min(prices[i],prices[i-1]);
        }
        return ans < 0 ? 0 : ans;
    }
};