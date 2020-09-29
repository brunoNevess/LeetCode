class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int answer = 0;
        for(int bit = 30;bit>=0;bit--){
            if ( (1 << bit & m) != (1<< bit & n) ) break;
            else answer |= (1 << bit & m );
        }
        return answer;
    }
};