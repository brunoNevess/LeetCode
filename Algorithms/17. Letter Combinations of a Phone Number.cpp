class Solution {
public:
    
 
    
    void backtrack(unordered_map<int,string>& m,string& digits,string& s,int pos,vector<string>& ans){
        if(pos == digits.size()){
            ans.push_back(s);
            return;
        }
       string curr = m[digits[pos]-'0'] ;
       for(int j=0;j<curr.size() ;j++){
                s += curr[j];
                backtrack(m,digits,s,pos+1,ans);
                s.pop_back();
        }
    }
    
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<int,string> d;
        vector<string> s = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        for(int i=2;i<=9;i++) d[i] = s[i-2];
      
        string str = "";
       backtrack(d,digits,str,0,ans);
        return ans;
        
        
    }
};