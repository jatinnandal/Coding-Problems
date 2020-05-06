class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1)
            return 0;
        int minm = prices[0];
        int maxm = 0;
        for(int i=1;i<prices.size();i++){
            maxm = max(maxm,prices[i]-minm);
            minm = min(minm,prices[i]);
        }
        return maxm;
    }
};
