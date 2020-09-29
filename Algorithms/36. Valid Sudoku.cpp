typedef pair<char,int> ii;
class Solution {
public:
    
    int boxNum(int i,int j){
        return 3*floor(i/3)+floor(j/3);
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        map<ii,bool> haveIseeninRow;
        map<ii,bool> haveIseeninCol;
        map<ii,bool> isInBox;
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(board[i][j]!='.'){
                    
                
                ii p(board[i][j],i);
                ii p2(board[i][j],j);
                ii p3(board[i][j],boxNum(i,j));
                if(haveIseeninRow[p]) return false;
                if(haveIseeninCol[p2]) return false;
                if(isInBox[p3]) return false;
                
                haveIseeninRow[p] = true;
                haveIseeninCol[p2] = true;
                isInBox[p3] = true;
            }
            }
        }
        return true;
        
        
    }
};