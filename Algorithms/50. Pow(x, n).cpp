class Solution {
public:
    double help(double x,long long n){
            if(n==0) return 1;
            if(n==1) return x;
            double y = help(x,n/2);
            if(n % 2 == 0) {

                    return y*y;
            }
            else{
                    return y*y*x;
            }
            
    } 
    double myPow(double x, int n) {
            if(x==0) return 0;
            if(x==1) return 1;
            if(x==-1) return n%2 == 0 ? 1:-1;
            long long n2 = (long long)n;
            if(n<0) {
                    x = 1.0/x;
                    long long n2 = -n2; ;
            }
            return help(x,n2);
    }
};