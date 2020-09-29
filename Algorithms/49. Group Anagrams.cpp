class Solution {
public:
        
    string original(string x){
            sort(x.begin(),x.end());
            return x;
    }    
        
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int> key;
        vector<vector<string>> ans;
        int i=0;
        for(auto st:strs){
                string x = original(st);
                if(key.find(x) == key.end()){
                        key[x] = i++;
                        ans.push_back(vector<string>());
                }
                ans[key[x]].push_back(st);
        }
        return ans;
    }           
};