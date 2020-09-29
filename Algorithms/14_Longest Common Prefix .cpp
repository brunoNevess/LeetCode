class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        for(int j=0;j<strs[0].size();++j){
                auto x = strs[0][j];
                for(int i=1;i<strs.size();++i){
                    if(j < strs[i].size()){
                        if(strs[i][j] != x){ 
                            return ans;
                            
                        }
                    }
                    
                    else return ans;
                }
                ans+=x;
          
        }
        return ans;
    }
};