class Solution {
public:
    map<vector<int>, int>m;
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        permutations(nums, nums.size());
        return result;
    }

    void permutations(vector<int>& nums, int len){
        if (m.find(nums) != m.end()) return;
        if (len == 1){
            result.push_back(nums);
            m[nums]=1;
            return;
        }

        int i=(int)nums.size()-len;
        for (int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            permutations(nums, len-1);
            swap(nums[i], nums[j]);
        }

    }
};