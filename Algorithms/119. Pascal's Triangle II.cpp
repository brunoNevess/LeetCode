class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> c;
        c.push_back(1);
        if (rowIndex == 0) return c;
        c.push_back(1);
        if (rowIndex == 1) return c;
        for (int i=2;i<=rowIndex;i++){
            vector<int> n;
            n.push_back(1);
            for(int i=0;i<c.size()-1;i++){
                int sum = c[i]+c[i+1];
                n.push_back(sum);
            }
            n.push_back(1);
            c = n;
        }
        return c;
        
    }
};