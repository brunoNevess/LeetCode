class Solution {
public:

    string gcd(string s1,string s2){
        
        if(s2.size() > s1.size()) return gcd(s2,s1);
     
        if(s1 == s2) return s1;
        int l = s2.size();
        if(s1.substr(0,l) == s2) return gcd(s2,s1.substr(l));
        else return "";
        
        
    }
    string gcdOfStrings(string str1, string str2) {
       
        return gcd(str1,str2);
    }
};

