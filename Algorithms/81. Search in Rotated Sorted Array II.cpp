class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
       
        if(n==0) return false;
        if(n==1) return nums[0] == target;
        int i = 0;
        while(i+1< n and nums[i] <= nums[i+1]) i++;
        bool a1 = binary_search(nums.begin(),nums.begin()+i+1,target);
        bool a2 = binary_search(nums.begin()+i+1,nums.end(),target);
        return a1 or a2;
    }
};