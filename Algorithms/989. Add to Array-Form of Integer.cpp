class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> k;
        while(K > 0 ){
            k.push_back(K%10);
            K/=10;
        }
        reverse(A.begin(),A.end());
        auto& v1 = A;
        auto& v2 = k;
        if(v2.size() > v1.size()) swap(v1,v2);
        int base = 10;
        int carry = 0 ;
        vector<int> ans;
        int i = 0;
        for(i=0;i<v2.size();i++){
            int s = v1[i] + v2[i] + carry;
            carry = s/base;
            ans.push_back(s%base);
        }
        for(int j=i;j<v1.size();j++){
            int s = v1[j]+carry;
            carry = s/base;
            ans.push_back(s%base);
        }
        if(carry) ans.push_back(carry);
        reverse(begin(ans),end(ans));
        return ans;
        
    }
};