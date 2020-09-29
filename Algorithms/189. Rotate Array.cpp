// cyclical replacement

class Solution {
public:
    
     void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int save = nums[0];
        int first = 0,i=0;
        int count = n;
        while(count--){
            int next = (i+k)%n;
            swap(nums[next],save);
            i = next;
            if(i == first){
                i = (i+1)%n;
                first = i;
                save = nums[i];
            }
        }
    }
};    

// i ----> (i+k)%N