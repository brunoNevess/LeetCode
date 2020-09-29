class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
      
        int diff = INT_MAX;
        int ret;
        for(int i = 0;i<n;i++){
            int j = i+1;
            int k = n-1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if(abs(sum-target)<diff) {
                    diff = abs(sum-target);
                    ret = sum;
                }
                if(sum < target) j++;
                else k--;
            }
        }
        return ret;
    }
};
