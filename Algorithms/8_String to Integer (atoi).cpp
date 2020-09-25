class Solution {
public:
    int myAtoi(string str) {
            
           long long ans = 0;
           int i=0;
           int sgn = 1;
           while(i < str.size() and str[i]==' ') i++;
           if(i == str.size() or (not isdigit(str[i]) and str[i]!='-' and str[i] != '+' )) return 0;
           if(str[i]=='-' or str[i] == '+'){
                   sgn = str[i] == '+' ? 1:-1;
                   i++;
           }
           while(i<str.size() and isdigit(str[i])){
                   int r = str[i]-'0';
                   ans = 10*ans + r;
                   if(ans > INT_MAX or ans*sgn < INT_MIN) {
                           
                           return sgn == 1 ? INT_MAX : INT_MIN;
                           
                   }
                   i++;
           }
           ans*= sgn;
           if (ans < INT_MIN) return INT_MIN;
          
           return ans;
           
           
           
        
    }
};