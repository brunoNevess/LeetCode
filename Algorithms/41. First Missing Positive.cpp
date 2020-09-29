class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        sort(nums.begin(),nums.end());
        if(nums[0]<=0 and nums[nums.size()-1]<=0) return 1;
        
        auto it = unique(nums.begin(),nums.end());     
        int i = 0;
        int c = 1;
        while(nums[i]<=0) i++;
        for(;i<nums.size();i++,c++){
            if(nums[i]!=c) return c;
        }
        return c;
        
        
        
    }
};