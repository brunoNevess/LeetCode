class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        vector<vector<char>> grid(n);
        int col = 0;
        bool down;
        for(char c:s){
            grid[col].push_back(c);
            if(col == 0 or col == n-1) down = col == 0 ? true:false;
            if(down) col++;
            else col--;
        }
        string ans = "";
        for(int i=0;i<grid.size();i++){
            string tmp = "";
            for(char c:grid[i]) tmp += c;
            ans+=tmp;
        }
        return ans;
    }
};