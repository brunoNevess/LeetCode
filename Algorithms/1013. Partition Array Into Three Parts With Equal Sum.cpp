class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int x3 = accumulate(begin(A),end(A),0);
        if(x3%3 !=0 ) return false;
        int x = x3/3;
        int n = A.size();
        int sum = 0;
        int found = 0;
        for(int i=0;i<n;i++){
            sum += A[i];
            if(sum == x) {
                found++;
                sum = 0;
            }
        }
        return found >= 3;
        
       
    }
};



// -----x------2x-------3x