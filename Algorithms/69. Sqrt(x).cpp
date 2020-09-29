class Solution {
public:
    int mySqrt(int x) {
        
        int i = 0;
        int j = x;
        int med;
        while (i<=j){
            med = (j-i)/2+i;
            long long s = (long long)med*(long long)med;
            if(s==x) return med;
            if(s>x) j = med-1;
            else i = med+1;
        }
        return i-1;
        
        
        
        
    }
};