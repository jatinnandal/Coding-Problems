class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_map<int,bool> mp;
        for(int n: nums){
            mp[n] = true;
        }
        int maxm = 1;
        for(int n:nums){
            int cnt = 1;
            if(!mp.count(n-1)&&mp.count(n+1)){
                int temp = n+1;
                while(mp.count(temp)){
                    temp++;
                    cnt++;
                }
            }
            maxm = max(maxm,cnt);
        }
        return maxm;
    }
};
