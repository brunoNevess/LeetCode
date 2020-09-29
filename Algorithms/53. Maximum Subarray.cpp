class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int me = *max_element(nums.begin(),nums.end());
        int sum = 0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            if(sum < 0) sum = 0;
            ans = max(ans,sum);
        }
        return ans == 0 ? me : ans;
        
        
        
    }
};