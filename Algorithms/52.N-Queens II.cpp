class Solution {
public:
    
    int ans;
    int col = -1;
    int N = -1;
    bool isSafe(vector<string>& b,int r, int c){
        for(int i=0;i!=c;i++){
            if(b[r][i] == 'Q') return false;
        }
        for(int i=r-1,j = c-1;i>=0 and j>=0 ; i--,j--){
            if(b[i][j] == 'Q') return false;
        }
        for(int i=r+1,j = c-1;i<N and j>=0;i++,j--){
            if(b[i][j] == 'Q') return false;
        }
        return true;
    }
    
    void helper(int r,int c,vector<string>& b){
    
        if (c >=col){
            ans ++;
            return;
        }
        
        for(int i=0;i<N;i++){
            if(isSafe(b,i,c)){
                b[i][c] = 'Q';
                helper(i,c+1,b);
                b[i][c] = '.';
            }
        }   
        return ;
    }
    
    
    
    int totalNQueens(int n) {
        string x = "";
        col = n;
        N = n;
        for(int i=0;i<n;i++) x+= '.';
        vector<string> b(n,x);
        helper(0,0,b);
        return ans;
        
    }
};