class Solution {
public:
    
    // 1 3 5 4 7
    //1 3 5 7 and 1 3 4 7
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n),count(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(length[j] >= length[i]){
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                    else if(length[j]+1 == length[i]) count[i] += count[j];
                    
                }
            }
        }
        int maxLen = -1;
        for(int x:length) maxLen = max(maxLen,x);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(length[i] == maxLen) ans += count[i];
        }
        return ans;
    }
};