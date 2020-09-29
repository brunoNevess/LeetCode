class Solution {
public:
    bool isHappy(int n) {
        
        set<int> s;
        while(true){
            int next = 0;
            while(n){
                int r = n%10;
                next += r*r;
                n/=10;
            }
            n = next;
            if(n==1) return true;
            if(s.find(n)==s.end()) s.insert(n);
            else return false;
        }
        
    }
};