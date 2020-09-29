class Solution {
public:
    

    void dfs(vector<vector<char>>& c,int i,int j){
        
        if(i >= c.size() or i<0 or j>=c[0].size() or j<0) return;
        
        if(c[i][j] == 'X' or c[i][j] == 'V') return;
        
        c[i][j] = 'V';
        dfs(c,i+1,j);
        dfs(c,i-1,j);
        dfs(c,i,j+1);
        dfs(c,i,j-1);
    }
    
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i == 0 or i == board.size()-1 or j==0 or j == board[0].size()-1)
                    if(board[i][j] == 'O') dfs(board,i,j);
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j] = board[i][j] == 'V' ? 'O' : 'X';
            }
        }
        return;
    }
};