class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string last = "11";
        
        for(int i=3;i<=n;i++){
            string next = "";
            for(int j=0;j<last.size();j++){
                int count = 1;
                char say = last[j];
                while (j+1<last.size() and last[j+1] == last[j] ) {
                    j++;
                    count++;
                }
                next += (to_string(count) + (say));
                
            }
            last = next;
        }
        return last;
        
        
    }
};