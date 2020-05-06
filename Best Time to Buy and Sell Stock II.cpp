class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int i=0;
        int profit = 0;
        int n = nums.size();
        while(i<n){
            int l_max = nums[0],l_min = nums[0];
            while(i<n-1 && nums[i+1]<=nums[i])
                i++;
            l_min = nums[i];
            if(i==(n-1))
                break;
            i++;
            while(i<n && nums[i-1]<=nums[i])
                i++;
            l_max = nums[i-1];
            profit+=(l_max - l_min);   
        }
        return profit;
    }
};
