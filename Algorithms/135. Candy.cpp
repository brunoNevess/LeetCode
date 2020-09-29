class Solution {
public:
    

    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        
        for(int i =0;i+1<n;i++){
            if(ratings[i+1]>ratings[i]) candies[i+1] = candies[i]+1;
        }
        for(int j=n-1;j>=1;j--){
            if(ratings[j] < ratings[j-1]) candies[j-1] = max(candies[j]+1,candies[j-1]);
        }
        int ans = 0;
        for(auto x:candies) ans += x;
        return ans;
        
        
    }
};