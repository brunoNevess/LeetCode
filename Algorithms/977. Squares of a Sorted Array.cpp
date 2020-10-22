class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        
        int n = a.size();
        int i = 0;
        int j = n-1;
        vector<int> ans;
        while(i<=j){
            if(abs(a[i]) > abs(a[j])){
                ans.push_back(a[i]*a[i]);
                i++;
            }
            else{
                ans.push_back(a[j]*a[j]);
                j--;
            }
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};