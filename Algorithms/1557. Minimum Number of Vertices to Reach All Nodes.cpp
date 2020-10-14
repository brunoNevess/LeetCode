class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n);
        vector<int> ans;
        for(auto& e:edges) inDeg[e[1]]++;
        for(int i=0;i<n;i++) if(!inDeg[i]) ans.push_back(i);
        return ans;
    }
};