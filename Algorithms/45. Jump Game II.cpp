class Solution {
public:
    int jump(vector<int>& nums) {
         pair<int,int> interval{0,0}; //store the interval which i can reach
        int jumps = 0;
        int n = nums.size();
        if (n == 1) return 0;
        while(true){
            //iterate
            int can_reach = -1;
            for(int i=interval.first;i<=interval.second;++i){
                can_reach = max(can_reach,i+nums[i]);
            }
            jumps++;
            if (can_reach >= n-1) break;
            
            interval.first = interval.second;
            interval.second = can_reach;
        }
        return jumps;
    }
};
     