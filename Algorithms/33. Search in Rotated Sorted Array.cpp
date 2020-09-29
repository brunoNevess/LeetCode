class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int p = n;
        for(int i=0;i+1<n;i++){
                if(nums[i+1]<nums[i]){
                    p = i+1;
                    break;
                }
            
        }
        auto it1 = lower_bound(nums.begin(),nums.begin()+p,target);
        if(it1!=nums.end() and *it1 == target) return distance(nums.begin(),it1);
        auto it2 = lower_bound(nums.begin()+p,nums.end(),target);
        if(it2!=nums.end() and *it2 == target) return distance(nums.begin(),it2);
        return -1;
        
    }
};