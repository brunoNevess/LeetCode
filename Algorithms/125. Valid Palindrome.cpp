class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        string p = "";
        for(char c:s){
            if(isalpha(c) or isdigit(c))  p += tolower(c);
        }
        string p2 = p;
        reverse(p.begin(),p.end());
        return (p == p2);
    }
};