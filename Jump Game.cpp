class Solution {
public:
    bool canJump(vector<int>& nums){
        int n = nums.size();
        int maxm = nums[0];
        for(int i=1;i<n;i++){
            if(maxm<=0)
                return false;
            maxm-=1;
            maxm = max(maxm,nums[i]);
            
        }
        return true;
    }
};
