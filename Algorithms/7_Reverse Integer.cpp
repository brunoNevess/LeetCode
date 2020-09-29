class Solution {
public:
    int reverse(int x) {
        std::string s = std::to_string(x);
        std::reverse((x < 0) ? s.begin()+1 : s.begin(), s.end());
        try { return std::stoi(s); } catch (...) { return 0; } // catch overflow 
    }
};