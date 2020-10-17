class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        
        int i = n-1,j=0;
        
        while(i>=0 and j < m){
            if(grid[i][j] < 0){
                i--;
                count += (m-j);
            }
            else {
                j++;
            }
        }
        return count;
    }
};


