class Solution {
public:
      
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        for(auto& path: paths){
            string& x = path;
            string filePath = "";
            int i = 0;
            while(x[i]!=' '){
                filePath+= x[i++];
            }
            i++;
            while(i<x.size()){
                string file = "";
                while(x[i]!= '('){
                    file+=x[i++];
                }
                i++;
                string content = "";
                while(x[i]!=')'){
                    content+=x[i++];
                }
                i+=2;
                string _filePath = filePath+"/"+file;
                mp[content].push_back(_filePath);
            }
        }
        vector<vector<string>> ans;
        for(auto it=begin(mp);it!=end(mp);it++){
            if(it->second.size() > 1 )ans.push_back(it->second);
        }
        return ans;
    }
};