class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int sum = 0;
        int i = 0,j=0;
        int ans = INT_MAX;
        int n = nums.size();
        while(j<n){
            if(sum<s){
                sum += nums[j];
                j++;
            }
            if(sum >=s){
                while(i <= j and sum>=s){
                    ans = min(ans,j-i);
                    sum -= nums[i];
                    i++;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};