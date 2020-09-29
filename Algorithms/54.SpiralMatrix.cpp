class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix.size();
        if(n==0) return v;
        int m = matrix[0].size();
        int top = 0,bottom = n-1,left = 0,right = m-1;
      
        int t = m*n;
        int c = 0;
        while(c<t){
            for(int i = left;i<=right && c<t;i++,c++) v.push_back(matrix[top][i]);
            top++;
            for(int i = top;i<=bottom && c<t;i++,c++) v.push_back(matrix[i][right]);
            right--;
            for(int i = right;i>=left && c<t;i--,c++) v.push_back(matrix[bottom][i]);
            bottom--;
            for(int i = bottom;i>=top && c < t;i--,c++) v.push_back(matrix[i][left]);
            left++;
        }
        return v;
    }
};