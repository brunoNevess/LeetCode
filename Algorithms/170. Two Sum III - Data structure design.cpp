
class TwoSum {
public:
    /** Initialize your data structure here. */
    vector<int> sums;
    unordered_set<int> cache;
    TwoSum() {
        
    }
    /** Add the number to an internal data structure.. */
    void add(int number) {
        
        auto it = std::lower_bound( sums.begin(), sums.end(), number); // find proper position in descending order
        sums.insert( it, number ); // insert before iterator it
    }
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if(cache.count(value)) return true;
        int i = 0,j = sums.size() -1 ;
        
        while(i<j){
            
            int sum = sums[i] + sums[j];
            
            if(sum == value){
                cache.insert(sum);
                return true;
            }
            if(sum > value) j--;
            else i++;
        }
        return false;
        
    }
};