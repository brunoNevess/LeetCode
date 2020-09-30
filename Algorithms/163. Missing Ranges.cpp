class Solution {
public:   
    string formRange(int low, int high){
        if(low == high)
            return to_string(low);
        else{
            return to_string(low) + "->" + to_string(high);
        }
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size() == 0){
            res.push_back(formRange(lower, upper));
            return res;
        }
        
        if(nums[0] > lower){
            res.push_back(formRange(lower, nums[0] - 1));
        }
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i -1] + 1)
                res.push_back(formRange(nums[i -1] + 1, nums[i] - 1));
        }
        
        if(nums[nums.size() - 1] < upper)
            res.push_back(formRange(nums[nums.size() - 1] + 1, upper));     
        return res;
    }
};