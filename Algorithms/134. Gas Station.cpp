class Solution {
public:
    
    // bool try_ind(vector<int>& gas,vector<int>& cost,int startIndex){
    //     int n = gas.size();
    //     int current = 0;
    //     int i = startIndex;
    //     while(true){
    //         current += gas[i];
    //         if(current< cost[i]) return false;
    //         current -= cost[i];
    //         int next_station = (i+1)%n;
    //         if(next_station == startIndex) return true;
    //         i = next_station;
    //     }
    // }
    // if from A------>B does not work , then any point between this path wont work
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int sum = 0,balance = 0,start = 0;
        for(int i=0;i<gas.size();i++){
            sum += (gas[i]-cost[i]);
            if(sum < 0 ){
                start = (i+1)%gas.size();
                sum = 0;
            }
            balance += (gas[i]-cost[i]);
        }
        return balance >=0 ? start : -1;
    }
};