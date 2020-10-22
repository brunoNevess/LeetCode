class Solution {
public:
    
    // 1 3 5 4 7
    //1 3 5 7 and 1 3 4 7
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> length(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(length[j] >= length[i]){
                        length[i] = length[j] + 1;
                    }
                }
            }
        }
        int maxLen = -1;
        for(int x:length) maxLen = max(maxLen,x);
        
        return maxLen;
    }
};