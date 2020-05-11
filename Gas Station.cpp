class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0;
        for(int i=0;i<gas.size();i++){
            s+=(gas[i]-cost[i]);
        }
        if(s<0)
            return -1;
        int ans = 0;
        s=0;
        for(int i=0;i<gas.size();i++){
            s+=(gas[i] - cost[i]);
            if(s<0){
                s=0;
                ans = i+1;
            }
        }
        return ans;
    }
};
