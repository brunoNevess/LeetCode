class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0 ) return {};
        vector<vector<int>> ans;
        vector<int> c;
        c.push_back(1);
        ans.push_back(c);
        if (numRows == 1) return ans;
        c.push_back(1);
        ans.push_back(c);
        if (numRows == 2) return ans;
        for (int i=3;i<=numRows;i++){
            vector<int> current = ans[ans.size()-1];
            vector<int> n;
            n.push_back(1);
            for(int i=0;i<current.size()-1;i++){
                int sum = current[i]+current[i+1];
                n.push_back(sum);
            }
            n.push_back(1);
            ans.push_back(n);
        }
        return ans;
        
    }
};