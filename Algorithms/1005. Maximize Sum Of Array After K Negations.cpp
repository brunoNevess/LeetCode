class Solution {
public:
    int sum(const vector<int>& A){
        return accumulate(begin(A),end(A),0);
    }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        
        int n = A.size();
        if(n == 0) return 0;
        sort(begin(A),end(A));
        
        if(A[0] == 0) return sum(A);
        if(A[0] > 0){
            while(K--) A[0] = -A[0];
            return sum(A);
        }
        int i = 0;
        int lastNeg,firstPos;
        while(i < n and A[i] < 0 and K){
            K--;
            A[i] = -A[i];
            lastNeg = i;
            i++;
        }
        if(A[i] == 0) return sum(A);
        firstPos = i;
        int j = abs(A[firstPos]) > abs(A[lastNeg]) ? lastNeg : firstPos;
        while(K--) A[j] = -A[j];
        
        return sum(A); 
    }
};




