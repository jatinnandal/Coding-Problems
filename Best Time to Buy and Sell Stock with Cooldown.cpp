class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,buy_1=0,sell=0,sell_1=0,sell_2=0;
        int n = prices.size();
        if(n<2)
            return 0;
        
        /*
            On current day we can buy the stock if we have not done any transaction a day before.
            So, buy = max(buy_1,sell_2-price[i]) // max of if we dont buy(prev buy buy_1) and if we buy
            then profit till 2 day before(sell_2) - current price.
            
            Same is done for price except we can also sell on the next day of buy.
            sell = max(sell_1, buy_1+price[i])
        */
        buy_1 = -prices[0];
        buy = max(buy_1,-prices[1]);
        sell = max(sell_1,buy_1+prices[1]);
        
        sell_2 = sell_1;
        sell_1 = sell;
        buy_1 = buy;
        for(int i=2;i<prices.size();i++){
            buy = max(buy_1,sell_2-prices[i]);
            sell = max(sell_1,buy_1+prices[i]);
            
            sell_2 = sell_1;
            sell_1 = sell;
            buy_1 = buy;
        }
        return sell;
    }
};
