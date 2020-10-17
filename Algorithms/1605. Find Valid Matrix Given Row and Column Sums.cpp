class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int H = rowSum.size();
        int W = colSum.size();
        vector<vector<int>> ans(H,vector<int>(W,0));
        int i=0,j=0;
        while(i < H and j < W){
                int m = min(rowSum[i],colSum[j]);
                ans[i][j] += m;
                rowSum[i] -= m;
                colSum[j] -= m;
                i = rowSum[i] == 0 ? i+1:i;
                j = colSum[j] == 0 ? j+1:j;
        }
        return ans;
    }
};