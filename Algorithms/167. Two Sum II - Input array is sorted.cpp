class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j = numbers.size()-1;
        while(i<j){
                int r = numbers[i]+numbers[j];
                if(r>target) j--;
                else if(r<target) i++;
                else {
                        return vector<int>({i+1,j+1});
                }
        }
        return vector<int>();
            
    }
};