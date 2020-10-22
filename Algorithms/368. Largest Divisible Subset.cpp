class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        vector<int> length(n);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[i] = vector<int>({nums[i]});
            for(int j=i-1;j>=0;j--){
                if(nums[i] % nums[j] == 0){
                    if(length[j] >= length[i]){
                        length[i] = length[j] + 1;
                        mp[i] = mp[j];
                        mp[i].push_back(nums[i]);
                    }
                }
            }
        }
        int maxLen = -1;
        for(int x:length) maxLen = max(maxLen,x);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(length[i] == maxLen) return mp[i];
        }
        return vector<int>();
        
    }
};


