class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string s = "";
        if(numerator == 0) return "0";
        if(numerator < 0 ^ denominator < 0) s += '-';
        long long n = abs(numerator);
        long long d = abs(denominator);
        
        s += to_string(n/d);    
        if(n%d==0) {
            return s;
        }
        s += '.';
        unordered_map<long long,int> seen;
     
        long long r = n%d;
        while(r!=0){
            if(seen.count(r)){
                s.insert(seen[r],"(");
                s.push_back(')');
                return s;
            }
            seen[r] = s.size();
            r*=10;
            s += to_string(r/d);
            r = r%d;
        }
        return s;
        
        
        
    }
};

// 0.(012)

// 10 = 5*2

// 4 / 333

// 4 = 333*0 + 4
// 40 = 0*333 + 40
// 400 = 1*333 + 67
// 670 = 2*333 + 4
    
// 0.