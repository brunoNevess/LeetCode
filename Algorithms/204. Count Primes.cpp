class Solution {
public:
    vector<int> primes;
    int s(int n){
       vector<int> p;
        p.assign(n+1,1);
        
        p[1] = 0;
        int l = (int)sqrt(n);
        for (int i=2;i<=l;i++){
            if(p[i]){
                for(int j=2*i;j<n;j+=i) p[j]=0;
            }
        }
        int ans = 0;
        for(int i=2;i<n;i++){
            if(p[i]) ans++;
        }
        return ans;
    }
    int countPrimes(int n) {
        if (n==0 or n==1) return 0; 
        return s(n);
    }
};