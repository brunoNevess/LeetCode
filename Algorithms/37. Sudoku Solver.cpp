class Solution {
public:
    
   
    
    
    int isSafe(int x,int y,char n,vector<vector<char>>& board){
        for (int i = 0,j=0;i<9  && j<9;i++,j++)
            if((board[i][y] == n or board[x][j] == n)) return false;
        int startx = x/3*3;
        int starty = y/3*3; 
        for(int xx = startx; xx<startx+3; xx++){
            for(int yy = starty; yy<starty+3; yy++){
                if(board[xx][yy] == n){
                    return false;
                }
            }
        }
        return true;
              
        
    }
    
    
    bool solve(vector<vector<char>>& board){
      
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for (int n=1;n<=9;n++){
                        if(isSafe(i,j,n+'0',board)){
                        board[i][j] = n + '0';
                        if (solve(board)) return true;
                       else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
        
    
};