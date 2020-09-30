class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] <= nums[n-1]) return *min_element(nums.begin(),nums.end());
        int i = 0;
        while(1){
            if(nums[i]>nums[i+1]) break;
            i++;
        }
        i++;
        return *min_element(nums.begin()+i,nums.end());
        
        
        
    }
};